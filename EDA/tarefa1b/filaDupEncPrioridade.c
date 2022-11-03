
#include "arq.h"

struct descF *cria()
{
    struct descF *desc = (struct descF *)malloc(sizeof(struct descF));
    if (desc != NULL)
    {
        desc->cauda = NULL;
        desc->frente = NULL;
        desc->refMovel = NULL;
        desc->tamInfo = sizeof(info);
    }
    return desc;
}

int insereNaFila(info *novo, struct descF *fila)
{
    int result;
    struct noFila *novoNoFila = NULL, *visitado = NULL;
    if ((novoNoFila = (struct noFila *)malloc(sizeof(struct noFila))) != NULL)
    {
        memcpy(&(novoNoFila->dados), novo, fila->tamInfo); // novoNoFila->dados = *novo;
        if (fila->frente == NULL && fila->cauda == NULL)   /*fila vazia*/
        {
            novoNoFila->atras = novoNoFila->defronte = NULL;
            fila->frente = fila->cauda = fila->refMovel = novoNoFila;
        }
        else
        {
            visitado = fila->frente; /*maior prioridade na frente */
            while (visitado->atras != NULL && (visitado->dados.idade >= novo->idade))
                visitado = visitado->atras;

            if (visitado->dados.idade < novo->idade) /* novo item fica a frente do visitado */
            {
                novoNoFila->atras = visitado;
                if (visitado->defronte != NULL)
                {
                    novoNoFila->defronte = visitado->defronte;
                    visitado->defronte->atras = novoNoFila;
                }
                else
                { // novo item é o de maior prioridade de todos na fila, sendo a nova frente
                    novoNoFila->defronte = NULL;
                    fila->frente = novoNoFila;
                }
                visitado->defronte = novoNoFila;
                novoNoFila->atras = visitado;
            }
            else
            { // novo item é o de menor prioridade de todos na fila, sendo a nova cauda
                novoNoFila->defronte = visitado;
                novoNoFila->atras = NULL;
                visitado->atras = novoNoFila;
                fila->cauda = novoNoFila;
            }
        }
        return 1;
    }

    return 0;
};

int tamanhoDaFila(struct descF *fila)
{
    int tam = 0;
    struct noFila *aux = fila->cauda;

    while (aux != NULL)
    {
        tam++;
        aux = aux->defronte;
    }

    return tam;
};

int reinicia(struct descF *fila)
{
    int status = 0;
    struct noFila *aux = NULL;

    if (fila->frente != NULL && fila->cauda != NULL)
    {
        aux = fila->cauda->defronte;
        while (aux != NULL)
        {
            free(fila->cauda);
            fila->cauda = aux;
            aux = aux->defronte;
        }

        free(fila->cauda);
        fila->frente = NULL;
        fila->cauda = NULL;
        fila->refMovel = NULL;
        status = 1;
    }
    return status;
};

struct descF *destroi(struct descF *fila)
{
    reinicia(fila);
    free(fila);
    return NULL;
};

int buscaNaCauda(info *ele, struct descF *fila)
{
    int pos = 0;

    if (fila->cauda != NULL && fila->frente != NULL)
    {
        struct noFila *aux = fila->cauda;
        for (int i = 0; i < tamanhoDaFila(fila); i++)
        {
            if (ele->idade == aux->dados.idade && strcmp(aux->dados.nome, ele->nome) == 0)
            {
                memcpy(ele, &(aux->dados), fila->tamInfo);
                break;
            }
            aux = fila->cauda->defronte;
            pos++;
        }
    }

    return pos;
};

int buscaNaFrente(info *ele, struct descF *fila)
{
    int pos = 0;

    if (fila->cauda != NULL && fila->frente != NULL)
    {
        struct noFila *aux = fila->frente;
        for (int i = 0; i < tamanhoDaFila(fila); i++)
        {
            if (ele->idade == aux->dados.idade && strcmp(aux->dados.nome, ele->nome) == 0)
            {
                memcpy(ele, &(aux->dados), fila->tamInfo);
                break;
            }
            aux = fila->frente->atras;
            pos++;
        }
    }

    return pos;
};

int buscaNoRefMovel(info *ele, struct descF *fila)
{
    struct noFila *aux1 = fila->cauda, *aux2 = fila->frente, *aux3 = fila->refMovel;
    int nC = aux1->dados.idade, nF = aux2->dados.idade, nRM = aux3->dados.idade;
    nC = (nC - ele->idade) < 0 ? (nC - ele->idade) * (-1) : (nC - ele->idade);
    nF = (nF - ele->idade) < 0 ? (nF - ele->idade) * (-1) : (nF - ele->idade);
    nRM = (nRM - ele->idade) < 0 ? (nRM - ele->idade) * (-1) : (nRM - ele->idade);

    int pos;
    if (fila->cauda != NULL && fila->frente != NULL)
    {
        struct noFila *aux = fila->refMovel;
        if (nF <= nC)
        {

            while (ele->idade != aux->dados.idade && strcmp(aux->dados.nome, ele->nome) != 0)
            {
                aux = aux->defronte;
            }
            memcpy(ele, &(aux->dados), fila->tamInfo);
            pos = buscaNaFrente(ele, fila);
        }
        else
        {
            while (ele->idade != aux->dados.idade && strcmp(aux->dados.nome, ele->nome) != 0)
            {
                aux = aux->atras;
            }
            memcpy(ele, &(aux->dados), fila->tamInfo);
            pos = buscaNaCauda(ele, fila);
        }
    }
    return pos;
};

int retiraDaFila(info *ele, struct descF *fila)
{
    int status = 0;
    struct noFila *aux1 = fila->cauda, *aux2 = fila->frente, *aux3 = fila->refMovel;

    if (fila->cauda != NULL && fila->frente != NULL)
    {
        int nC = aux1->dados.idade, nF = aux2->dados.idade, nRM = aux3->dados.idade;
        nC = (nC - ele->idade) < 0 ? (nC - ele->idade) * (-1) : (nC - ele->idade);
        nF = (nF - ele->idade) < 0 ? (nF - ele->idade) * (-1) : (nF - ele->idade);
        nRM = (nRM - ele->idade) < 0 ? (nRM - ele->idade) * (-1) : (nRM - ele->idade);

        if (aux1 == fila->frente)
        { // caso tenha 1 elemento apenas
            free(fila->frente);
            fila->frente = fila->cauda = fila->refMovel = NULL;
        }
        else
        {
            if (nC <= nRM && nC <= nF)
            {
                struct noFila *auxi1, *rEle;
                int pos = buscaNaCauda(rEle, fila);

                auxi1 = rEle->atras;
                rEle->atras->defronte = rEle->defronte;
                rEle->defronte->atras = fila->refMovel = auxi1;
                free(rEle);
                free(auxi1);
                free(ele);
                rEle = auxi1 = ele = NULL;
            }
            else if (nRM <= nF && nRM <= nC)
            {
                struct noFila *auxi1, *rEle;
                int pos = buscaNoRefMovel(rEle, fila);

                auxi1 = rEle->atras;
                rEle->atras->defronte = rEle->defronte;
                rEle->defronte->atras = fila->refMovel = auxi1;

                free(rEle);
                free(auxi1);
                free(ele);
                rEle = auxi1 = ele = NULL;
            }
            else if (nF <= nC && nF <= nRM)
            {
                struct noFila *auxi1, *rEle;
                int pos = buscaNaFrente(rEle, fila);

                auxi1 = rEle->atras;
                rEle->atras->defronte = rEle->defronte;
                rEle->defronte->atras = fila->refMovel = auxi1;

                free(rEle);
                free(auxi1);
                free(ele);
                rEle = auxi1 = ele = NULL;
            }
        }
        status = 1;
    }

    return status;
};

int testaVazia(struct descF *fila)
{
    if (fila->frente == NULL && fila->cauda == NULL)
    {
        return 1;
    }

    return 0;
};

int inverte(struct descF *fila);