
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

typedef struct infoList
{
    int col;
    int lin;
} InfoList;

typedef struct noListaPos
{
    InfoList dados;
    struct noListaPos *prox;
} NoListaPos;

typedef struct DescListaPos
{
    int tamInfo;
    NoListaPos *inicio;
} DescListaPos;

//======================APLICACAO=====================

//======================FILA=====================
DescListaPos *criaListPos(int tamInfo);
int tamanhoDaLista(DescListaPos *p);
int reinicia(DescListaPos *p);
DescListaPos *destroi(DescListaPos *p);

int insereNaPoslog(int posLog, InfoList *novo, DescListaPos *p);
int insereNovoUltimo(InfoList *reg, DescListaPos *p);
int insereNovoPrimeiro(InfoList *reg, DescListaPos *p);

int buscaOultimo(InfoList *reg, DescListaPos *p);
int buscaOprimeiro(InfoList *reg, DescListaPos *p);
int buscaNaPoslog(int posLog, InfoList *reg, DescListaPos *p);

int removeDaPoslog(int Poslog, InfoList *reg, DescListaPos *p);
int removeOultimo(InfoList *reg, DescListaPos *p);
int removeOprimeiro(InfoList *reg, DescListaPos *p);

int testaVazia(DescListaPos *p);
int inverte(DescListaPos *p);
DescListaPos *destroi(DescListaPos *p);
