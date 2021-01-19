#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "tty.h"
#include "ansi.h"

// #define TEST

const uint32_t boje[] = {
	0,
	0xaa0000,
	0x00aa00,
	0xaa5500,
	0x0000aa,
	0xaa00aa,
	0x00aaaa,
	0xaaaaaa,
};

// TODO: videti
const uint32_t boje2[] = {
	0,
	0xff0000,
	0x00ff00,
	0xffaa00,
	0x0000ff,
	0xff00ff,
	0x00ffff,
	0xffffff,
};

static void set_ansi_style(struct tty_info *tty, int code) {
	if(code == 0) {
		tty->fg = DEFAULT_FGCOLOUR;
		tty->bg = DEFAULT_BGCOLOUR;
	} else if(code == 1) {
		//tty->
	} else if(code == 7) {
		uint32_t t = tty->fg;
		tty->fg = tty->bg;
		tty->bg = t;
	} else if(code == 10) {
		// Primary or default font
		
	} else if(code >= 30 && code <= 37) {
		tty->fg = boje[code-30];
	} else if(code == 39) {
		tty->fg = DEFAULT_FGCOLOUR;
	} else if(code >= 40 && code <= 47) {
		tty->bg = boje[code-40];
	} else if(code == 49) {
		tty->bg = DEFAULT_BGCOLOUR;
	} else {
		printf("Unknown style: %d\n", code);
	}
}

void std_ansi(struct tty_info *tty, size_t inbuf_size, char *inbuf) {
#ifdef TEST
	fprintf(stderr, "ANSI sequence: ");
	for(size_t i = 0; i < inbuf_size; i++)
		if(isgraph(inbuf[i]))
			putchar(inbuf[i]);
		else
			printf("'\\x%x'", inbuf[i]);
	putchar('\n');
#endif
	switch(inbuf[inbuf_size-1]) {
		// TODO: Dodaj podršku za podrazumevane vrednosti
		case 'm':
			{
				int a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				// printf("ANSI COL: %d\n", a);
				set_ansi_style(tty, a);
				// printf("ANSI Style sequence: ");
				// for(size_t i = 0; i < inbuf_size; i++)
				// 	if(isgraph(inbuf[i]))
				// 		putchar(inbuf[i]);
				// 	else
				// 		printf("'\\x%x'", inbuf[i]);
				// putchar('\n');
				// asd
			}
			break;
		case 'A':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI UP: %ld\n", a);
				tty->cury = tty->cury <= a ? 0 : tty->cury - a;
			}
			break;
		case 'B':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI DOWN: %ld\n", a);
				tty->cury = tty->cury + a > tty->vis-1 ? tty->vis-1 : tty->cury + a;
			}
			break;
		case 'C':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI LEFT: %ld\n", a);
				tty->curx = tty->curx + a > tty->sir-1 ? tty->sir-1 : tty->curx + a;
			}
			break;
		case 'D':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("                 ANSI RIGHT: %ld\tinb:^[%s\n", a, inbuf+1);
				tty->curx = tty->curx <= a ? 0 : tty->curx - a;
			}
			break;
		case 'E':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI LINE UP: %ld\n", a);
				tty->curx = 0;
				tty->cury = tty->cury < a ? 0 : tty->cury - a;

			}
			break;
		case 'F':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI DOWN: %ld\n", a);
				tty->curx = 0;
				tty->cury = tty->cury + a > tty->vis-1 ? tty->vis-1 : tty->cury + a;
			}
			break;
		case 'G':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI CHA: %ld\n", a);
				tty->curx = a < tty->sir ? a-1 : tty->sir-1;
			}
			break;
		case 'f':
		case 'H':
			{
				/*
				printf("CUR ANSI sequence: ");
				for(size_t i = 0; i < inbuf_size; i++)
					if(isgraph(inbuf[i]))
						putchar(inbuf[i]);
					else
						printf("'\\x%x'", inbuf[i]);
				putchar('\n');
				*/

				size_t i = 2;
				size_t a = 0, b = 0;
				if(inbuf[i] == ';') {
					i++;
				} else {
					for(i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
						a *= 10, a += inbuf[i] - '0';
					i++;
				} 
				if(isdigit(inbuf[i]))
					for(; isdigit(inbuf[i]) && (i < inbuf_size); i++)
						b *= 10, b += inbuf[i] - '0';

				a = a ? a : 1;
				b = b ? b : 1;

				// printf("ANSI CUR POS: %ld, %ld\n", a, b);

				tty->curx = b < tty->sir ? b-1 : tty->sir-1;
				tty->cury = a < tty->vis ? a-1 : tty->vis-1;
			}
			break;

		case 'J':
			// printf("ANSI CLEAR(J): %c\n", inbuf[2]);
			switch(inbuf[2]) {
				case '1':
					for(size_t i = 0;
							i < tty->curx+tty->cury*tty->sir; i++)
						tty->cbuf[i] = (struct cchar){' ', tty->fg, tty->bg};
					break;
				case '2':
					for(size_t i = 0; i < tty->sir*tty->vis; i++)
						// printf("i: %ld\n", i), tty->cbuf[i] = (struct cchar){' ', tty->fg, tty->bg};
						tty->cbuf[i] = (struct cchar){' ', tty->fg, tty->bg};
					break;
				case '0':
				default:
					for(size_t i = tty->curx+tty->cury*tty->sir;
							i < tty->sir*tty->vis; i++)
						tty->cbuf[i] = (struct cchar){' ', tty->fg, tty->bg};
					break;
			}
			crtaj(tty);
			break;

		case 'K':
		// printf("\\e%.*s\n", (int)inbuf_size-1, inbuf+1);
		// printf("ANSI CLEAR(K): %c\n", inbuf[2]);
		switch(inbuf[2]) {
			case '1':
				for(size_t x = 0; x <= tty->curx; x++)
					tty->cbuf[x+tty->cury*tty->sir] =
							(struct cchar){' ', tty->fg, tty->bg};
				break;
			case '2':
				for(size_t x = 0; x < tty->sir; x++)
					tty->cbuf[x+tty->cury*tty->sir] =
						(struct cchar){' ', tty->fg, tty->bg};
				break;
				case '0':
				default:
					for(size_t x = tty->curx; x < tty->sir; x++)
						tty->cbuf[x+tty->cury*tty->sir] =
							(struct cchar){' ', tty->fg, tty->bg};
					break;
			}
			crtaj(tty);
			break;

		case 'L':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;

				// printf("ANSI Insert Line: %ld\n", a);
				if(tty->cury+a >= tty->vis-1) {
					for(size_t y = tty->cury+1; y < tty->vis; y++)
						for(size_t x = 0; x < tty->sir; x++)
							tty->cbuf[x + y*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};

					for(size_t x = 0; x < tty->sir; x++)
						tty->cbuf[x + (tty->vis-1)*tty->sir] = tty->cbuf[x + tty->cury*tty->sir];
					for(size_t x = 0; x < tty->sir; x++)
						tty->cbuf[x + tty->cury*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};
				} else {
					size_t num = (tty->vis-1) - (tty->cury+a);
					for(size_t i = num-1; i > (a-1); i--)
						for(size_t x = 0; x < tty->sir; x++)
							// TODO: Popraviti 
							printf("OVDE i: %6ld, cury: %6ld, a: %6ld, num: %6ld, %6ld\n",
									i, tty->cury, a, num, tty->cury+i-a), 
								tty->cbuf[x + (tty->cury+a+i)*tty->sir] = tty->cbuf[x + (tty->cury+i)*tty->sir];

					for(size_t i = 0; i < a; i++)
						for(size_t x = 0; x < tty->sir; x++)
							tty->cbuf[x + (tty->cury+i)*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};

				}

				crtaj(tty);
				crtaj_cursor(tty);

			}
			break;

		case 'M':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				printf("ANSI Delete Line: %ld\n", a);
				a = a ? a : 1;
				a = a > tty->vis - tty->cury - 1 ? tty->vis - tty->cury - 1 : a;
				size_t num = tty->vis-tty->cury-a;

					// TODO: Završiti

					for(size_t i = 0; i < num; i++)
						for(size_t x = 0; x < tty->sir; x++)
							tty->cbuf[x + (tty->cury+i)*tty->sir] = tty->cbuf[x + (tty->cury+i+a)*tty->sir];
					/*
					for(size_t y;;)
						for(size_t x = 0; x < tty->sir; x++)
							tty->cbuf[x + (tty->cury+i)*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};
								*/
			}
			break;

		case 'P':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				printf("ANSI Delete Chars: %ld\n", a);
				// TODO: Završiti 

				for(size_t x = tty->curx; x + a < tty->sir; x++)
					tty->cbuf[x + tty->cury*tty->sir] = tty->cbuf[x+a + tty->cury*tty->sir];
				for(size_t x = tty->sir-a; x < tty->sir; x++)
					tty->cbuf[x + tty->cury*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};

				crtaj_red(tty, tty->cury);
				crtaj_cursor(tty);

			}
			break;

		case 'X':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				printf("ANSI Erase Chars: %ld\n", a);
				
				size_t maks = tty->curx + a + 1 > tty->sir ? tty->sir : tty->curx + a + 1;
				for(size_t x = tty->curx; x < maks; x++)
					tty->cbuf[x + tty->cury*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};

				crtaj_red(tty, tty->cury);
				crtaj_cursor(tty);

			}
			break;

		case 'd':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				// printf("ANSI LPA: %ld\n", a);
				tty->curx = a < tty->sir-1 ? a : tty->sir-1;
			}
			break;

		case 'n':
			{
				int a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				// printf("ANSI n: %d\n", a);
				switch(a) {
					case 6:
						{
						char str[64];
						snprintf(str, 64, "\x1b[%ld;%ldR",
								tty->curx+1, tty->cury+1);
						write(tty->master, str, strlen(str));
						}
						break;

					default:
						printf("Unknown ANSI n: %d\n", a);
						break;
				}
			}
			break;
		case '@':
			{
				size_t a = 0;
				for(size_t i = 2; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				printf("ANSI Insert Blank: %ld\n", a);
				size_t kraj = tty->curx+a > tty->sir ? tty->sir : tty->curx+a;
				for(size_t i = tty->curx; i < kraj; i++)
					tty->cbuf[i + tty->cury*tty->sir] = (struct cchar){' ', tty->fg, tty->bg};
				crtaj_red(tty, tty->cury);
			}
			break;

		default:
			// Verovatno će ostati ovako
// #ifdef TEST
			fprintf(stderr, "Unkown ANSI sequence: ");
			for(size_t i = 0; i < inbuf_size; i++)
				if(isgraph(inbuf[i]))
					putchar(inbuf[i]);
				else
					printf("'\\x%x'", inbuf[i]);
			putchar('\n');
// #endif
			break;
	}

}

void priv_ansi(struct tty_info *tty, size_t inbuf_size, char *inbuf) {
	switch(inbuf[inbuf_size-1]) {
		case 'l':
			{
				int a = 0;
				for(size_t i = 3; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				switch(a) {
					case 12:
					case 2004:
						break;
					case 25:
						tty->hide_cursor = 1;
						break;
					default:
						printf("%d ", a);
						goto default1;
				}
			}
			break;

		case 'h':
			{
				int a = 0;
				for(size_t i = 3; isdigit(inbuf[i]) && (i < inbuf_size); i++)
					a *= 10, a += inbuf[i] - '0';
				a = a ? a : 1;
				switch(a) {
					case 12:
					case 2004:
						break;
					case 25:
						tty->hide_cursor = 0;
						break;
					default:
						printf("%d ", a);
						goto default1;
				}
			}
			break;

default1:
		default:
			printf("Unknown Private ANSI sequence: ");
			for(size_t i = 0; i < inbuf_size; i++)
				if(isgraph(inbuf[i]))
					putchar(inbuf[i]);
				else
					printf("'\\x%x'", inbuf[i]);
			putchar('\n');
			break;
	}

}
