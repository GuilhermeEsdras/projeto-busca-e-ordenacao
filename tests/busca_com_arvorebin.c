#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// gcc ./tests/busca_com_arvorebin.c -o bca

typedef int t_temp;

typedef struct arvore arvore;

typedef struct arvore
{
    int id;
    t_temp temp;
    arvore *esq, *dir;
} Local;

void criaArvore(Local **l)
{
    *l = NULL;
}

Local *insereTemp(Local *l, int id, t_temp temp)
{
    if (l == NULL)
    {
        Local *aux = (Local *)malloc(sizeof(Local));

        aux->id = id;
        aux->temp = temp;
        aux->esq = NULL;
        aux->dir = NULL;

        return aux;
    }

    else if (id > l->id)
    {
        l->esq = insereTemp(l->esq, id, temp);
    }

    else
    {
        l->dir = insereTemp(l->dir, id, temp);
    }
}

t_temp buscaTemp(Local *l, int id)
{
    if (l == NULL) return -1;

    if (l->id == id) {
        return l->temp;
    }

    t_temp auxEsq = buscaTemp(l->esq, id);
    t_temp auxDir = buscaTemp(l->dir, id);

    if (auxEsq != -1) return auxEsq;
    else return auxDir;
}

int main()
{

    int amostras;
    scanf("%d", &amostras);

    Local *locais;
    criaArvore(&locais);

    register int i;
    for (i = 0; i < amostras; i++)
    {
        int id;
        t_temp temp;
        scanf("%d %d", &id, &temp);
        locais = insereTemp(locais, id, temp);
    }

    unsigned long int consultas, c;
    scanf("%ld", &consultas);

    for (c = 0; c < consultas; c++)
    {
        int id;
        scanf("%d", &id);

        t_temp tempEncontrada = buscaTemp(locais, id);
        printf("%d\n", tempEncontrada);
    }

    return false;
}