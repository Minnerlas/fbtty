#define _XOPEN_SOURCE 600
#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>     
#include <sys/select.h>
#include <linux/input.h>


#include "tty.h"
#include "psf1font.h"
#include "crtanje.h"
#include "resman.h"
#include "ansi.h"


#define SHELL "/bin/dash"

extern char _binary____zap_ext_light18_psf_start[];
extern char _binary____zap_ext_light18_psf_end[];
// extern char _binary_zap_ext_light16_psf_start[];
// extern char _binary_zap_ext_light16_psf_end[];

extern const uint32_t sr_latin_keymap[0x27d];
extern const uint32_t sr_latin_keymap_shift[0x27d];
extern const uint32_t sr_latin_keymap_altgr[0x27d];


int spawn(struct tty_info *tty, int master, int slave) {
	pid_t p;

	char t1[64] = {0}, t2[64] = {0} ;
	snprintf(t1, 64, "COLUMNS=%ld", tty->sir);
	snprintf(t2, 64, "LINES=%ld", tty->vis);

	// char *env[] = { "TERM=dumb", t1, t2, NULL };
	char *env[] = { "TERM=ansi", t1, t2, NULL };
	// char *env[] = { "TERM=st-256color", t1, t2, NULL };

	p = fork();
	if (p == 0) {
		close(master);

		/* Create a new session and make our terminal this process'
		 * controlling terminal. The shell that we'll spawn in a second
		 * will inherit the status of session leader. */
		setsid();
		if (ioctl(slave, TIOCSCTTY, NULL) == -1) {
			perror("ioctl(TIOCSCTTY)");
			return 1;
		}

		dup2(slave, 0);
		dup2(slave, 1);
		dup2(slave, 2);
		close(slave);

		execle(SHELL, "-" SHELL, (char *)NULL, env);
		return 1;
	} else if (p > 0) {
		close(slave);
		return 0;
	}

	perror("fork");
	return 1;
}

#define INBUF_MAKS 64

int run(struct tty_info *tty, int master, int kbdfd, int maxfd) {
	static char inbuf[INBUF_MAKS] = {0};
	static size_t inbuf_size = 0;
	// static int ansi_gotovo = 0;

	size_t i;
	fd_set readable;
	char buf[1];
	int just_wrapped = 0;
	int out_of_bounds = 0;

	uint8_t utf_buf[5] = {0};
	int utf_size = 0;
	int utf_target_size = 0;
	int kraj_utf = 1;

	// maxfd = master > x11->fd ? master : x11->fd;

	for (;;) {
		FD_ZERO(&readable);
		FD_SET(master, &readable);
		FD_SET(kbdfd,  &readable);
		// FD_SET(x11->fd, &readable);

		if (select(maxfd + 1, &readable, NULL, NULL, NULL) == -1) {
			perror("select");
			return 1;
		}

		if (FD_ISSET(master, &readable)) {
			// printf("DBG: '%c'\n", buf[0]);
			if (read(master, buf, 1) <= 0) {
				/* This is not necessarily an error but also happens
				 * when the child exits normally. */
				fprintf(stderr, "Nothing to read from child: ");
				perror(NULL);
				return 1;
			}

			/*
			if(buf[0] == '\x1b')
				printf("buf: \\e\n");
			else if(buf[0] == '\n')
				printf("buf: \\n\n");
			else if(buf[0] == '\r')
				printf("buf: \\r\n");
			else if(buf[0] == ' ')
				printf("buf: _\n");
			else
				printf("buf: %c\n", *buf);
			*/


			if (buf[0] == '\r') {

				/* "Carriage returns" are probably the most simple
				 * "terminal command": They just make the cursor jump
				 * back to the very first column. */
				tty->curx = 0;
			} else {

				if (buf[0] != '\n') {
					// printf("DBG: %d: '%c'\n", (int)buf[0], buf[0]);
					/* If this is a regular byte, store it and advance
					 * the cursor one cell "to the right". This might
					 * actually wrap to the next line, see below. */

					if(buf[0] == '\t') {
						// printf("TAB\n");
						size_t t = tty->curx % 8 ? 8 - (tty->curx % 8) : 8;
						if(tty->curx + t <= tty->sir) {
							for(size_t i = 0; i < t; i++) 
								tty->cbuf[tty->cury * tty->sir + tty->curx++] = (struct cchar){' ', tty->fg, tty->bg};
							crtaj_red_kursor(tty, tty->cury);
						} else
							tty->curx += t;

					} else if(buf[0] == '\x1b' || inbuf[0] == '\x1b') { 
						inbuf[inbuf_size++] = buf[0];
						// printf("ANSI: \\e%.*s\n", inbuf_size-1, inbuf+1);
						if(inbuf_size == 2 && inbuf[1] != '[') {
							inbuf_size = 0, inbuf[0] = '\0';
						} else if(inbuf_size > 2 && (isalpha(inbuf[inbuf_size-1]) || inbuf[inbuf_size-1] == '@')) {
								// !(isdigit(inbuf[inbuf_size-1]) ||
								//   inbuf[inbuf_size-1] == ';' ||
								//   inbuf[inbuf_size-1] == '?')) {
						
							/*
							printf("ANSI sequence: ");
							for(size_t i = 0; i < inbuf_size; i++)
								if(isgraph(inbuf[i]))
									putchar(inbuf[i]);
								else
									printf("'\\x%x'", inbuf[i]);
							putchar('\n');
							*/

							if(inbuf[2] != '?')
								// Parsovanje standarnih ANSI kodova
								std_ansi(tty, inbuf_size, inbuf);
							else
								priv_ansi(tty, inbuf_size, inbuf);
							inbuf_size = 0;
							inbuf[0] = 0;
						}
					} else if(buf[0] == '\x8'){
						tty->curx = tty->curx > 1 ? tty->curx - 1 : 0;
					} else {
						// tty->cbuf[tty->cury * tty->sir + tty->curx] = (struct cchar){(uint8_t)buf[0]>127?ext_ascii[(uint8_t)buf[0]-128] :buf[0], tty->fg, tty->bg};
						// TODO

						if (tty->curx < tty->sir)
							out_of_bounds = 0;
						if (out_of_bounds) {
							tty->curx = 0;
							tty->cury++;
							just_wrapped = 1;
							out_of_bounds = 0;
						} else
							just_wrapped = 0;

						assert(tty->curx < tty->sir);

						uint32_t c = (uint8_t)buf[0];
						// printf("CHAR: %u\n", c);

						if(c <= 127) {
							if(!kraj_utf) {
								c = NEPOZNATO;
								utf_target_size = 0;
								utf_size = 0;
								utf_buf[0] = 0;
							}
							kraj_utf = 1;
						} else if(c > 127 || !kraj_utf) {
							// printf("UTF CHAR: 0x%x\n", (uint8_t)*buf);

							if((*buf & 0xc0) == 0xc0) {
								utf_buf[0] = *buf;
								utf_size = 1;
								kraj_utf = 0;
								if((uint8_t)*buf <= 0xdf) {
									utf_target_size = 2;
								} else if((uint8_t)*buf <= 0xef) {
									utf_target_size = 3;
								} else if((uint8_t)*buf <= 0xf7) {
									utf_target_size = 4;
								} else {
									utf_target_size = 0;
									utf_buf[0] = 0;
									utf_size = 0;
									c = NEPOZNATO;
									kraj_utf = 1;
								}
							} else if((c >= 0x80) && (c <= 0xbf)) {
								utf_buf[utf_size++] = *buf;
								kraj_utf = 0;
								// printf("ASDJHSAD: ");
								// for(int i = 0; i < utf_size; i++)
								// 	printf("%d ", utf_buf[i]);
								// putchar('\n');
								if(utf_size == utf_target_size) {
									c = utf_to_ucs32(utf_size, utf_buf);
									utf_target_size = 0;
									utf_buf[0] = 0;
									utf_size = 0;
									kraj_utf = 1;
								}
							} else {
								utf_target_size = 0;
								utf_buf[0] = 0;
								utf_size = 0;
								c = NEPOZNATO;
								kraj_utf = 1;
							}

						}

						if(kraj_utf) {
							if(c > 127)
								printf("UCS-32: %d\n", c);

							// TODO: Promeniti u proveru UTF-8 koda
							// Za sada služi kao provera tačnosti parsovanja, bez provere tačnosti UTF-8 koda
							assert(utf_size == 0);

							tty->cbuf[tty->cury * tty->sir + tty->curx] = (struct cchar){c, tty->fg, tty->bg};
							// printf("Char: %d\n", buf[0]);
							crtaj_char(tty, tty->curx, tty->cury);
							tty->curx++;
							if(tty->curx >= tty->sir)
								out_of_bounds = 1;
						}
					}


					/*
					if (tty->curx >= tty->sir) {
						tty->curx = 0;
						tty->cury++;
						just_wrapped = 1;
					} else
						just_wrapped = 0;
					*/

				} else if (!just_wrapped) {
					/* We read a newline and we did *not* implicitly
					 * wrap to the next line with the last byte we read.
					 * This means we must *now* advance to the next
					 * line.
					 *
					 * This is the same behaviour that most other
					 * terminals have: If you print a full line and then
					 * a newline, they "ignore" that newline. (Just
					 * think about it: A full line of text could always
					 * wrap to the next line implicitly, so that
					 * additional newline could cause the cursor to jump
					 * to the next line *again*.) */
					tty->cury++;
					just_wrapped = 0;
					crtaj_red_kursor(tty, tty->curx);
				}

				/* We now check if "the next line" is actually outside
				 * of the buffer. If it is, we shift the entire content
				 * one line up and then stay in the very last line.
				 *
				 * After the memmove(), the last line still has the old
				 * content. We must clear it. */
				if (tty->cury >= tty->vis) {
					memmove(tty->cbuf, &tty->cbuf[tty->sir],
							tty->sir * (tty->vis - 1) * sizeof(*tty->cbuf));
					tty->cury = tty->vis - 1;

					for (i = 0; i < tty->sir; i++)
						tty->cbuf[tty->cury * tty->sir + i] = (struct cchar){' ', tty->fg, tty->bg};
					// crtaj_red(tty, tty->curx);
					crtaj(tty);
				}
			}

			// TODO: Crtanje
			// x11_redraw(x11);
			// crtaj(tty);
			if(!out_of_bounds)
				crtaj_cursor(tty);

		}

		// const char tst[] = "uname -a\n";
		// write(master, tst, strlen(tst));
		if(FD_ISSET(kbdfd, &readable)) {
			static struct {
				uint8_t shift;
				uint8_t ctrl;
				uint8_t alt;
				uint8_t altgr;
				uint8_t capslock;
			} mod = {0};

			// TODO: Napraviti bolji drajver za tastaturu
			struct input_event ev;
			if(read(kbdfd, &ev, sizeof(ev)) != sizeof(ev))
				break;
			// if(ev.value > 0 && ev.type == EV_KEY && ev.code) {
			if(ev.type == EV_KEY && ev.code) {
				char ch;
				if(mod.shift || (mod.capslock && isalpha(ch)))
					ch = (char)sr_latin_keymap_shift[ev.code];
				else if(mod.altgr)
					ch = (char)sr_latin_keymap_altgr[ev.code];
				else
					ch = (char)sr_latin_keymap[ev.code];

				switch(ev.code) {
					case KEY_ENTER:
					if (ev.value > 0) {
						char t = 13;
						write(master, &t, 1);
					}
						break;
					case KEY_ESC:
					if (ev.value > 0) {
						char t = 27;
						write(master, &t, 1);
					}
						break;
					case KEY_CAPSLOCK:
						if(ev.value == 0)
							mod.capslock = !mod.capslock;
						break;
					case KEY_LEFTALT:
						if(ev.value)
							mod.alt = 1;
						else
							mod.alt = 0;
						break;
					case KEY_RIGHTALT:
						if(ev.value)
							mod.altgr = 1;
						else
							mod.altgr = 0;
						break;
					case KEY_LEFTSHIFT:
					case KEY_RIGHTSHIFT:
						if(ev.value)
							mod.shift = 1;
						else
							mod.shift = 0;
						break;
					case KEY_UP:
					{
					const char str[] = "\x1b[A";
					if(ev.value > 0)
						write(master, str, strlen(str)); 
					}
					break;
					case KEY_DOWN:
					{
					const char str[] = "\x1b[B";
					if(ev.value > 0)
						write(master, str, strlen(str)); 
					}
						break;
					case KEY_RIGHT:
					{
					const char str[] = "\x1b[C";
					if(ev.value > 0)
						write(master, str, strlen(str)); 
					}
						break;
					case KEY_LEFT:
					{
					const char str[] = "\x1b[D";
					if(ev.value > 0)
						write(master, str, strlen(str)); 
					}
						break;
					default:
						if(ch > 0 && ev.value > 0)
							write(master, &ch, sizeof(ch)); 
				}
				if(ch == '\n' && ev.value > 0)
					crtaj(tty);
				/*
				if(ch == '\n')
					write(master, &ch, sizeof(ch));
				else if(ch> 0)
					write(master, &ch, sizeof(ch)); 
				printf("Key:% 4i State:% 4i '%ls', %d\n", ev.code, ev.value, t, t[0]);
				if(ch == '\n')
					crtaj(tty);
				*/
			}

		}

		/*
		   if (FD_ISSET(x11->fd, &readable)) {
		   while (XPending(x11->dpy)) {
		   XNextEvent(x11->dpy, &ev); 
		   switch (ev.type) {
		   case Expose:
		   x11_redraw(x11); 
		   break;
		   case KeyPress:
		   x11_key(&ev.xkey, pty);
		   break;
		   }
		   }
		   }
		   */
	}

	return 0;
}

int main() {
	struct resman *rm = init_resman();
	int return_code = 0;
	int master = -1, maxfd = 2;
	if(!rm) {
		fprintf(stderr, "Error while allocating memory\n");
		return_code = 1;
		goto KRAJ;
	}

	struct fb *framebuffer = init_fb();
	if(!framebuffer) {
		fprintf(stderr, "Error while initializing the framebuffer\n");
		return_code = 1;
		goto KRAJ;
	}
	dodaj_resman(rm, framebuffer, (void (*)(void*))close_fb);

	struct psf1_header *font = 
		(struct psf1_header*)_binary____zap_ext_light18_psf_start;
	// struct psf1_header *font = (struct psf1_header*)_binary_zap_ext_light16_psf_start;
	if(font->magic[0] != PSF1_MAGIC0 || font->magic[1] != PSF1_MAGIC1) {
		fprintf(stderr, "Wrong magic number for PS1 font header\n");
		return_code = 1;
		goto KRAJ;
	}


	struct tty_info *tty = malloc(sizeof(*tty));
	if(!tty) {
		fprintf(stderr, "Error while allocating memory\n");
		return_code = 1;
		goto KRAJ;
	}
	dodaj_resman(rm, tty, (void (*)(void*))free);

	tty->fb          = framebuffer;
	tty->font        = font;
	tty->sir         = framebuffer->sir/8;
	tty->vis         = framebuffer->vis/(font->charsize);
	tty->curx        = tty->cury = 0;
	tty->mousex      = tty->mousey = 0;
	tty->master      = INT_MAX;
	tty->hide_cursor = 0;
	printf("%ld, %ld\n", tty->sir, tty->vis);

	struct cchar *cbuf = calloc(tty->sir * tty->vis, sizeof(*cbuf));
	if(!cbuf) {
		fprintf(stderr, "Error while allocating memory for the char buffer\n");
		return_code = 1;
		goto KRAJ;
	}
	dodaj_resman(rm, cbuf, (void (*)(void*))free);

	tty->cbuf   = cbuf;

	if((master = posix_openpt(O_RDWR | O_NOCTTY)) < 0) {
		fprintf(stderr, "Error while opening pseudoterminal device\n");
		return_code = 1;
		goto KRAJ;
	}

	if(master > maxfd)
		maxfd = master;

	tty->master = master;

	if(grantpt(master) < 0) {
		fprintf(stderr, "Error while opening pseudoterminal device\n");
		return_code = 1;
		goto KRAJ;
	}

	if(unlockpt(master) < 0) {
		fprintf(stderr, "Error while opening pseudoterminal device\n");
		return_code = 1;
		goto KRAJ;
	}

	const char *slave_path = ptsname(master);
	if(!slave_path) {
		fprintf(stderr, "Error while opening pseudoterminal device\n");
		return_code = 1;
		goto KRAJ;
	}

	int slave = open(slave_path, O_RDWR | O_NOCTTY);
	if(slave < 0) {
		fprintf(stderr, "Error while opening pseudoterminal device\n");
		return_code = 1;
		goto KRAJ;
	}

	if(slave > maxfd)
		maxfd = slave;

	int kbdfd = open("/dev/input/event3", O_RDONLY);
	if(kbdfd < 0) {
		fprintf(stderr, "Error while opening the keyboard\n");
		return_code = 1;
		goto KRAJ;
	}

	if(kbdfd > maxfd)
		maxfd = kbdfd;

	// draw_char(tty->fb, 0, 0, tty->font, nadji_uc(font, L"Ћ"[0]));

	if(spawn(tty, master, slave)) {
		fprintf(stderr, "Error: Couldn't start the shell\n");
		return_code = 1;
		goto KRAJ;
	}

	tty->fb->b = (struct boja){0, 0, 0, 0};
	tty->bg = DEFAULT_BGCOLOUR;
	tty->fg = DEFAULT_FGCOLOUR;
	clr_buff(tty, DEFAULT_FGCOLOUR, DEFAULT_BGCOLOUR);
	clr_scr(tty->fb);

	run(tty, master, kbdfd, maxfd);

KRAJ:
	if(master >= 0)
		close(master);
	oslobodi_resman(rm);
	exit(return_code);
}
