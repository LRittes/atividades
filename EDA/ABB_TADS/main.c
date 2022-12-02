#include <stdio.h>
#include "arq_interface.h"

int sizeStr(char str[]);

void getChar(int *init, char txt[], char tmp[]);

int main()
{
    char txt[50] = "aa bs cdr";
    int init = 0;
    char tmp[50];
    getChar(&init, txt, tmp);

    printf("%s\n", tmp);

    getChar(&init, txt, tmp);

    printf("%s\n", tmp);

    getChar(&init, txt, tmp);

    printf("%s\n", tmp);

    char *vetChars[] = {"aaa", "bbqb", "300"};
    InfoMain vet[2] = {{sizeStr(vetChars[0]), criaListaLC(sizeof(NoLC))}, {sizeStr(vetChars[1]), criaListaLC(sizeof(NoLC))}};

    ABB *arv = criaABB(sizeof(InfoMain));
    insereABB(arv, &vet[0]);

    DescLC *listaColi = criaListaLC(sizeof(NoLC));
    DescListaPos *listaPos = criaListPos(sizeof(NoLP));

    arv->raiz->dados.listColi = listaColi;

    NoLC *noLC = (NoLC *)malloc(sizeof(NoLC));

    InfoLC infoLc;
    infoLc.pos = listaPos;
    memcpy(&(infoLc.str), vetChars[0], sizeof(sizeof(char) * sizeStr(vetChars[0])));

    InfoLC infoLc2;
    infoLc2.pos = listaPos;
    memcpy(&(infoLc2.str), vetChars[1], sizeof(sizeof(char) * sizeStr(vetChars[1])));

    insereNaPoslogC(0, &infoLc, arv->raiz->dados.listColi);
    insereNaPoslogC(1, &infoLc2, arv->raiz->dados.listColi);

    // arv->raiz->dados.listColi->inicio = noLC;
    // arv->raiz->dados.listColi->inicio->dados = infoLc;

    printf("%s\n", arv->raiz->dados.listColi->inicio->dados.str);
    printf("%s\n", arv->raiz->dados.listColi->inicio->prox->dados.str);

    InfoLP dataLP;
    dataLP.col = 0;
    dataLP.lin = 1;

    InfoLP dataLP2;
    dataLP2.col = 3;
    dataLP2.lin = 4;

    insereNaPoslog(0, &dataLP, arv->raiz->dados.listColi->inicio->dados.pos);
    insereNaPoslog(1, &dataLP2, arv->raiz->dados.listColi->inicio->dados.pos);

    printf("%i\n", arv->raiz->dados.listColi->inicio->dados.pos->inicio->prox->dados.col);
    printf("%i\n", arv->raiz->dados.listColi->inicio->dados.pos->inicio->prox->dados.lin);

    return 0;
}

int sizeStr(char str[])
{
    int i;
    for (i = 0; i < str[i] != '\0'; i++)
        ;
    return i;
}

void getChar(int *init, char txt[], char tmp[])
{
    int initInt = (*init);
    for (int i = (*init); txt[i] != '\0'; i++)
    {
        if (txt[i] == ' ')
        {
            (*init) = i + 1;
            break;
        }
        if (i == sizeStr(txt) - 1)
            (*init) = i + 1;
    }
    for (int i = 0; i + initInt <= (*init); i++)
    {
        tmp[i] = txt[i + initInt];
        if (i == (*init) - initInt)
            tmp[i] = '\0';
    }
}