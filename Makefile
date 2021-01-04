DIR=$(shell pwd)
LIBDIR=lib
INCDIR=include/
# PREFIKS=LD_PRELOAD=${LIBDIR}/libsigil.so
# SIGIL=-lsigil 
# CFLAGS=-Wall -Wextra -g -L${LIBDIR} -I${INCDIR} ${SIGIL}
CFLAGS=-Wall -Wextra -Wpedantic -g -I${INCDIR} -O2 -pg
LINKFLAGS=-g -pg
CSOURCES=$(wildcard *.c)
HEADERS=$(wildcard include/*.h)
BINS=$(patsubst %.c,bin/%.o,$(CSOURCES))
OUT=fbtty

all: ${OUT}

${OUT}: $(BINS) font/fnt.o 
	gcc $^ -o $@ ${LINKFLAGS}

bin/%.o: %.c
	gcc ${CFLAGS} -c $< -o $@

run: ${OUT}
	${PREFIKS} ./${OUT}

dbg: ${OUT}
	${PREFIKS} gdb ./${OUT}

run_val: ${OUT}
	${PREFIKS} valgrind --leak-check=full --show-leak-kinds=all ./${OUT}

clean:
	rm -rvf bin/*

.PHONEY: clean
