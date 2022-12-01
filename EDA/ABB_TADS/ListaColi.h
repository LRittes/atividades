#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ListaPos.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct info
{
    DescListaPos *pos;
    char str[50];
} Info;

typedef struct noLC
{
    Info dados;
    struct noLC *prox;
} NoLC;

typedef struct DescLC
{
    int tamInfo;
    NoLC *inicio;
} DescLC;

//======================APLICACAO=====================

//======================FILA=====================
DescLC *criaListaLC(int tamInfo);
int tamanhoDaListaC(DescLC *p);
int reiniciaC(DescLC *p);
DescLC *destroiC(DescLC *p);

int insereNaPoslogC(int posLog, Info *novo, DescLC *p);
int insereNovoUltimoC(Info *reg, DescLC *p);
int insereNovoPrimeiroC(Info *reg, DescLC *p);

int buscaOultimoC(Info *reg, DescLC *p);
int buscaOprimeiroC(Info *reg, DescLC *p);
int buscaNaPoslogC(int posLog, Info *reg, DescLC *p);

int removeDaPoslogC(int Poslog, Info *reg, DescLC *p);
int removeOultimoC(Info *reg, DescLC *p);
int removeOprimeiroC(Info *reg, DescLC *p);

int testaVaziaC(DescLC *p);
int inverteC(DescLC *p);
DescLC *destroiC(DescLC *p);
