#ifndef ANSI_H
#define ANSI_H

#include <stdint.h>
#include <stddef.h>

#define DEFAULT_BGCOLOUR 0x0
#define DEFAULT_FGCOLOUR 0xaaaaaa

void std_ansi(struct tty_info *tty, size_t inbuf_size, char *inbuf);
void priv_ansi(struct tty_info *tty, size_t inbuf_size, char *inbuf);

#endif /* ANSI_H */
