#include "tty.h"

#include "psf1font.h"

#include <assert.h>

void 
put_piksel(struct tty_info *tty, size_t xoff, size_t yoff, size_t x, size_t y, uint32_t c) {
	if((xoff+x)<tty->fb->sir && (yoff+y)<tty->fb->vis) {
		if(!tty->fb) {
			set_px_color_int(tty->fb, c);
			put_px(tty->fb, x+xoff, y+yoff);
		} else {
			tty->fb->fb[x+xoff + (y+yoff)*tty->fb->stv_sir] = c;
		}
	}
}

void 
draw_char(struct tty_info *tty, size_t x, size_t y, int off, uint32_t ib, uint32_t ibg) {
	if(off<0)
		off = nadji_uc(tty->font, NEPOZNATO);
	int vel_char = tty->font->charsize;
	for(int j = 0; j<vel_char; j++) {
		uint8_t bajt = tty->font->karakteri[vel_char*off+j];
		for(int k = 0; k<8; k++) {
			if(k<=8)
				put_piksel(tty, x, y, k, j, (1<<(8-k-1)) & bajt ? ib : ibg);
		}
	}

}

void clr_buff(struct tty_info *tty, uint32_t fgboja, uint32_t bgboja) {
	for(size_t y = 0; y < tty->vis; y++)
		for(size_t x = 0; x < tty->sir; x++)
			tty->cbuf[x + y*tty->sir] = (struct cchar){' ', fgboja, bgboja};
}

void crtaj(struct tty_info *tty) {
	uint32_t ch;
	for(size_t y = 0; y < tty->vis; y++)
		for(size_t x = 0; x < tty->sir; x++)
			if((ch = tty->cbuf[x+y*tty->sir].ch) != 0)
				draw_char(tty, x*8, y*tty->font->charsize, 
					nadji_uc(tty->font, ch),
					tty->cbuf[x + y*tty->sir].fgcol, 
					tty->cbuf[x + y*tty->sir].bgcol);
}

void crtaj_cursor(struct tty_info *tty) {
	size_t x = tty->curx;
	size_t y = tty->cury;
	size_t t;
	static size_t prx = 0;
	static size_t pry = 0;
	static char prev_hide_cur = 0;
	assert(tty->curx < tty->sir);
	assert(tty->cury < tty->vis);
	if(!prev_hide_cur) {
		draw_char(tty, x*8, y*tty->font->charsize, 
				nadji_uc(tty->font, tty->cbuf[x + y*tty->sir].ch),
				tty->cbuf[x + y*tty->sir].bgcol,
				tty->cbuf[x + y*tty->sir].fgcol);
	}
	prev_hide_cur = tty->hide_cursor;

	t = prx;
	prx = x;
	x = t;
	t = pry;
	pry = y;
	y = t;
	if(!tty->hide_cursor) {
		draw_char(tty, x*8, y*tty->font->charsize, 
				nadji_uc(tty->font, tty->cbuf[x + y*tty->sir].ch),
				tty->cbuf[x + y*tty->sir].fgcol,
				tty->cbuf[x + y*tty->sir].bgcol);
	}
}

void crtaj_char(struct tty_info *tty, size_t x, size_t y) {
	assert(x < tty->sir);
	draw_char(tty, x*8, y*tty->font->charsize, 
			nadji_uc(tty->font, tty->cbuf[x + y*tty->sir].ch),
			tty->cbuf[x + y*tty->sir].fgcol,
			tty->cbuf[x + y*tty->sir].bgcol);
}

void crtaj_red(struct tty_info *tty, size_t red) {
	for(size_t x = 0; x < tty->sir; x++)
		draw_char(tty, x*8, red*tty->font->charsize,
			nadji_uc(tty->font, tty->cbuf[x + red*tty->sir].ch),
			tty->cbuf[x + red*tty->sir].fgcol,
			tty->cbuf[x + red*tty->sir].bgcol);
		
}

void crtaj_red_kursor(struct tty_info *tty, size_t red) {
	for(size_t x = 0; x < tty->curx; x++) {
		assert(x < tty->sir);
		draw_char(tty, x*8, red*tty->font->charsize, 
			nadji_uc(tty->font, tty->cbuf[x + red*tty->sir].ch), 
			tty->cbuf[x + red*tty->sir].fgcol,
			tty->cbuf[x + red*tty->sir].bgcol);
	}
		
}
