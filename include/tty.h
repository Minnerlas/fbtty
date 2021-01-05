#ifndef TTY_H
#define TTY_H

#include <limits.h>

#include "crtanje.h"

// Coloured char struct
struct cchar {
	uint32_t ch;                // Unicode code point 
	uint32_t fgcol;               // 4 byte foreground colour 
	uint32_t bgcol;               // 4 byte background colour 
};

struct tty_info {
	struct fb *fb;              // Frame buffer where to draw
	struct psf1_header *font;   // PSF1 font to use 
	size_t sir;                 // Width of the framebuffer in characters
	size_t curx;                // x position of the cursor
	size_t vis;                 // Height of the framebuffer in characters
	size_t cury;                // y position of the cursor
	size_t mousex;              // x position of the mouse cursor
	size_t mousey;              // y position of the mouse cursor
	uint32_t fg;                // Foreground colour
	uint32_t bg;                // Background colour
	int master;                 // PTTY master file descriptor
	uint16_t utf8:1;            // Is UTF-8 mode enabled
	uint16_t hide_cursor:1;     // Hide Cursor
	struct cchar *cbuf;         // Buffer for coloured characters on the screen
};

void 
put_piksel(struct tty_info *tty, size_t xoff, size_t yoff, size_t x, size_t y, uint32_t c);
void 
draw_char(struct tty_info *tty, size_t x, size_t y, int off, uint32_t ib, uint32_t ibg);
void clr_buff(struct tty_info *tty, uint32_t fgboja, uint32_t bgboja);
void crtaj(struct tty_info *tty);
void crtaj_cursor(struct tty_info *tty);
void crtaj_char(struct tty_info *tty, size_t x, size_t y);
void crtaj_red(struct tty_info *tty, size_t red);
void crtaj_red_kursor(struct tty_info *tty);

#endif /* TTY_H */
