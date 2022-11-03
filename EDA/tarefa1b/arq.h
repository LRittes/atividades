#include "string.h"

typedef struct info
{
	int idade;
	char nome[30];
} info;

struct noFila
{
	info dados;
	struct noFila *atras;
	struct noFila *defronte;
};

struct descF
{
	struct noFila *frente;
	struct noFila *cauda;
	struct noFila *refMovel;
	int tamInfo;
};

struct descF *cria();

int insereNaFila(info *, struct descF *);

int tamanhoDaFila(struct descF *);

int reinicia(struct descF *);

struct descF *destroi(struct descF *);

int buscaNaCauda(info *, struct descF *);

int buscaNaFrente(info *, struct descF *);

int buscaNoRefMovel(info *, struct descF *);

int retiraDaFila(info *, struct descF *);

int testaVazia(struct descF *);

int inverte(struct descF *);