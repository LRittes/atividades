#include <stdio.h>
#include "arq_interface.h"

int sizeStrCustom(char str[]);

int sizeStr(char str[]);

void getWord(int *init, char txt[], char tmp[]);

int howManySpaceIn(char str[]);

int calculateIntStr(char str[]);

InfoLC *criaILC(char word[]);

int main()
{
    char txt[50] = "563 Ana 372484 6640.00 35 Quimica #";

    int end = 0, time = howManySpaceIn(txt);

    ABB *arv = criaABB(sizeof(InfoMain));

    for (int i = 0; i <= time; i++)
    {
        char tmp[50];

        getWord(&end, txt, tmp);
        int t = calculateIntStr(tmp);

        // printf("%i\n", t);

        InfoMain aux = {t, criaListaLC(sizeof(InfoLC))};
        insereABB(arv, &aux);

        InfoMain *perc;
        // buscaABB(arv, perc, t);
        InfoLC auxLC = {criaListPos(), tmp};
        insereNaPoslogC(tamanhoDaListaC((*perc).listColi), &auxLC, (*perc).listColi);
        // printf("%s\n", arv->raiz->dados.listColi->inicio->dados.str);
        // NoLP *no = (NoLP *)malloc(sizeof(NoLP));

        // infoLc.pos = criaListPos(sizeof(struct infoLP));
        // memcpy(&(infoLc.str), tmp, sizeof(sizeof(char) * sizeStr(tmp)));
        // InfoLC info = {, *tmp};
        // memcpy(&(lista), info->pos, sizeof(InfoLC));

        // infoLc.pos = criaListPos(sizeof(NoLP));

        // free(auxLC);

        // printf("%i\n", (*perc).identificador);
        // InfoLC *auxLC = (InfoLC *)malloc(sizeof(InfoLC));
        // auxLC = (InfoLC *){criaListPos(sizeof(InfoLP)), tmp};
        // insereNaPoslogC(0, &auxLC, (*perc).listColi);

        // printf("%i\n\n", (*perc).identificador);
    }

    // char *vetChars[] = {"aaa", "bbqb", "300"};
    // InfoMain vet[2] = {{sizeStr(vetChars[0]), criaListaLC(sizeof(NoLC))}, {sizeStr(vetChars[1]), criaListaLC(sizeof(NoLC))}};

    // arv->raiz->dados.listColi = listaColi;

    // InfoLC infoLc;
    // infoLc.pos = listaPos;
    // memcpy(&(infoLc.str), vetChars[0], sizeof(sizeof(char) * sizeStr(vetChars[0])));

    // InfoLC infoLc2;
    // infoLc2.pos = listaPos;
    // memcpy(&(infoLc2.str), vetChars[1], sizeof(sizeof(char) * sizeStr(vetChars[1])));

    // insereNaPoslogC(0, &infoLc, arv->raiz->dados.listColi);
    // insereNaPoslogC(1, &infoLc2, arv->raiz->dados.listColi);

    // // arv->raiz->dados.listColi->inicio = noLC;
    // // arv->raiz->dados.listColi->inicio->dados = infoLc;

    // printf("%s\n", arv->raiz->dados.listColi->inicio->dados.str);
    // printf("%s\n", arv->raiz->dados.listColi->inicio->prox->dados.str);

    // InfoLP dataLP;
    // dataLP.col = 0;
    // dataLP.lin = 1;

    // InfoLP dataLP2;
    // dataLP2.col = 3;
    // dataLP2.lin = 4;

    // insereNaPoslog(0, &dataLP, arv->raiz->dados.listColi->inicio->dados.pos);
    // insereNaPoslog(1, &dataLP2, arv->raiz->dados.listColi->inicio->dados.pos);

    // printf("%i\n", arv->raiz->dados.listColi->inicio->dados.pos->inicio->prox->dados.col);
    // printf("%i\n", arv->raiz->dados.listColi->inicio->dados.pos->inicio->prox->dados.lin);

    return 0;
}

int sizeStr(char str[])
{
    int i;
    for (i = 0; str[i] != '\n'; i++)
        ;
    return i;
}

int sizeStrCustom(char str[])
{
    int i;
    for (i = 0; i < str[i] != ' ' && str[i + 1] != '#'; i++)
        ;
    return i;
}

int howManySpaceIn(char str[])
{
    int res;
    for (int i = 0; str[i] != '#'; i++)
    {
        if (str[i] == ' ' && str[i + 1] != '#')
            res++;
    }
    return res;
}

void getWord(int *end, char txt[], char tmp[])
{
    int init = (*end);
    for (int i = (*end); txt[i] != '#'; i++)
    {
        if (txt[i] == ' ' && txt[i + 1] != '#')
        {
            (*end) = i + 1;
            break;
        }
        else if (txt[i] == ' ' && txt[i + 1] == '#')
            (*end) = i;
    }
    for (int i = 0; i + init < (*end); i++)
    {
        if (i + init == (*end) - 1)
        {
            tmp[i] = '\0';
        }
        else
        {
            tmp[i] = txt[i + init];
        }
    }
}

int calculateIntStr(char str[])

{
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        res += (i + 1) * (int)str[i];
    }
    return res;
}
