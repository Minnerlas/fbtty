#include "crtanje.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>

struct fb *init_fb() {
	int ncit;
	size_t sir, vis, stv_sir;
	// Citanjem ovog fajla saznajemo koliko je bitova po pikselu
	FILE *f = fopen("/sys/class/graphics/fb0/bits_per_pixel", "r");
	if(!f)
		return NULL;
	int bpp = 0;
	ncit = fscanf(f, "%d", &bpp);
	fclose(f);
	if(ncit != 1)
		return NULL;


	bpp /= 8;
	// U ovom fajlu se nalazi ukupan broj bajtova po jednoj liniji
	f = fopen("/sys/class/graphics/fb0/stride", "r");
	if(!f)
		return NULL;
	ncit = fscanf(f, "%zu", &stv_sir);
	fclose(f);
	if(ncit != 1)
		return NULL;
	stv_sir /= bpp;

	f = fopen("/sys/class/graphics/fb0/virtual_size", "r");
	if(!f)
		return NULL;
	ncit = fscanf(f, "%zu,%zu", &sir, &vis);
	fclose(f);
	if(ncit != 2)
		return NULL;

	struct fb *t = malloc(sizeof(*t));
	t->sir = sir;
	t->vis = vis;
	t->stv_sir = stv_sir;
	t->buf = fopen("/dev/fb0", "r+");
	t->b = (struct boja){0xff, 0xff, 0xff, 0};
	t->vel = stv_sir*vis*bpp;

	t->fb = mmap (0, t->vel, PROT_READ | PROT_WRITE, MAP_SHARED, fileno(t->buf), 0);
	if(t->fb == MAP_FAILED)
		printf("GREŠKA\n"), t->fb = NULL;

	return t;
}

void close_fb(struct fb *t) {
	if(t->fb != NULL)
		munmap(t->fb, t->vel);
	fclose(t->buf);
	free(t);
}

void put_px(struct fb *t, size_t x, size_t y) {
	if(t->fb == NULL) {
		fseek(t->buf, (x+y*(t->stv_sir))*sizeof(t->b), SEEK_SET);
		fwrite(&t->b, sizeof(t->b), 1, t->buf);
	} else {
		union {
			uint32_t br;
			struct boja b;
		} tmp;
		tmp.b = t->b; 
		t->fb[x + y*t->stv_sir] = tmp.br;
	}
}

void set_px_color_int(struct fb *t, uint32_t c) {
	t->b.R = (c&0xff0000) >> 16;
	t->b.G = (c&0xff00) >> 8;
	t->b.B = (c&0xff);
}

void clr_scr(struct fb *t) {
	if(t->fb == NULL) {
		fseek(t->buf, 0, SEEK_SET);
		for(size_t y = 0; y < t->vis; y++)
			for(size_t x = 0; x < t->sir; x++)
				fwrite(&t->b, sizeof(t->b), 1, t->buf);
	} else {
		for(size_t y = 0; y < t->vis; y++) 
			for(size_t x = 0; x < t->stv_sir; x++) {
				union {
					uint32_t br;
					struct boja b;
				} tmp;
				tmp.b = t->b; 
				t->fb[y*t->stv_sir + x] = tmp.br;
			}
	}
}
