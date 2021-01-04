#include "psf1font.h"

//#define TEST

#include <limits.h>

#ifdef TEST
#include <stdio.h>
#endif


int nadji_uc(struct psf1_header *font, int uc) {
	if (uc >= (1<<16))
		return -1;
	int vel_char = font->charsize;
	const int mod = (font->mode) & PSF1_MODE512;
	uint8_t *tabela = font->karakteri+(mod?512:256)*vel_char;
	int ucc = uc;
	if(!(font->mode & PSF1_MODEHASTAB))
		return uc;
	/* TODO: Kod za pretrvaranje iz jednog u drugi "endianes"
	   {
	   struct t {
	   uint8_t b[2];
	   } *t = (struct t*)&uc;
	   ucc = 256*t->b[0]+t->b[1];
	   }
	   printf("ucc: %x\n", ucc);
	   */

	int n = 0;

	uint16_t *t = (uint16_t*)tabela;
	while(n < (mod ? 512 : 256)) {
		if(*t==PSF1_SEPARATOR)
			n++;
		if(*t==ucc)
			return n;
		t++;
		//printf("%x\n", (int)*t);
	}

#ifdef TEST
	if(uc != 7)
		printf("Nepoznati karakter: U+%d\n", (uint8_t)uc);
#endif
	return -1;
}


uint32_t utf_to_ucs32(int utf_size, uint8_t *utf_buf) {
	uint32_t c = 0;
	if((uint8_t)*utf_buf <= 0xdf) {
		c = *utf_buf & 0x1f;
	} else if((uint8_t)*utf_buf <= 0xef) {
		c = *utf_buf & 0xf;
	} else if((uint8_t)*utf_buf <= 0xf7) {
		c = *utf_buf & 0x7;
	}
	for(int i = 1; i < utf_size; i++)
		c = (c << 6) + (utf_buf[i] & 0x3f);

	return c;
}



// Nije skroz implementirano ali ni ne treba bolje za ovaj font
/*
void print_utf8(struct psf1_header *font, const char *s1) {
	uint8_t *s = (uint8_t*)s1;
	while(*s) {
		if(*s<128)
			print_char(font, nadji_uc(font, *s++));
		else if(*s < 0b11100000 && *s>0b10000000) {
			if(*(s+1)) {
				print_char(font, nadji_uc(font, (*s&0b11111)*64+(*(s+1)&0b111111))), s+=2;
			} else {
				print_char(font, nadji_uc(font, NEPOZNATO));
				return;
			}

		} else if(*s < 0b11110000) {
			if(*(s+1) && *(s+2)) {
				int uc = (*s&0b1111)*4096+(*(s+1)&0b111111)*64+(*(s+2)&0b111111);
				print_char(font, nadji_uc(font, uc));
				s+=3;
			} else {
				print_char(font, nadji_uc(font, NEPOZNATO));
				while(*s<0b11000000) s++;
			}
		} else 
			while(*s<0b11000000) s++;

	}
}
*/
