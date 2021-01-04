#ifndef PSF1FONT_H

#include <stdint.h>
#include <stddef.h>

#define PSF1_MAGIC0      0x36
#define PSF1_MAGIC1      0x04

#define PSF1_MODE512     0x01
#define PSF1_MODEHASTAB  0x02
#define PSF1_MODEHASSEQ  0x04
#define PSF1_MAXMODE     0x05

#define PSF1_SEPARATOR   0xFFFF
#define PSF1_STARTSEQ    0xFFFE

#define NEPOZNATO        0XFFFD
#define PSF1FONT_H

struct psf1_header {
	unsigned char magic[2];     /* Magic number */
	unsigned char mode;         /* PSF font mode */
	unsigned char charsize;     /* Character size */
	uint8_t karakteri[];
};


int nadji_uc(struct psf1_header *font, int uc);

#define EXT_ASCII_SIZE 128
extern const uint32_t ext_ascii[EXT_ASCII_SIZE];

#endif /* PSF1FONT_H */
