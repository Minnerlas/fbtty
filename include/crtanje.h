#ifndef CRTANJE_H
#define CRTANJE_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#define SIR_UKUPNO 1376
#define SIR_VIDLJIVO 1366
#define VIS 768

struct boja {
	uint8_t B: 8;
	uint8_t G: 8;
	uint8_t R: 8;
	uint8_t nista: 8;
};

struct fb {
	FILE *buf;
	size_t stv_sir;
	size_t sir;
	size_t vis;
	struct boja b;
	size_t vel;
	uint32_t *fb;
};

struct fb *init_fb();
void close_fb(struct fb *t);
void put_px(struct fb *t, size_t x, size_t y);
void set_px_color_int(struct fb *t, uint32_t c);
void clr_scr(struct fb *t);

#endif /* CRTANJE_H */
