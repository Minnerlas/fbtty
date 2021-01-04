#ifndef RESMAN_H
#define RESMAN_H

struct _clan {
	void *res;
	void (*dealokator)(void*);
};

struct _dniz {
	struct _clan *niz;
	size_t duz;
	size_t stvduz;
};

struct _dniz *_napravi_dniz();
void _oslobodi_dniz(struct _dniz *niz);
int _dodaj_dniz(struct _dniz* niz, struct _clan c);

struct resman {
	struct _dniz dniz;
};

struct resman *init_resman();
int dodaj_resman(struct resman *rm, void *p, void (*f)(void*));
void oslobodi_resman(struct resman *rm);

#endif /* RESMAN_H */
