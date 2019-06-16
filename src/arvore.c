/*
 * Arquivo  : arvore.c
 * Tipo     : Complemento de biblioteca 
 *            Contem o corpo das funcoes do arquivo "arvore.h"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 - Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem a implementacao e corpo das funcoes 
 *      relacionadas a arvore binaria usando a linguagem C,
 *      cuja nomenclatura e descricoes estao localizadas na
 *      biblioteca "arvore.h".
 * 
 */

/* Biblioteca (.h) necessaria para as funcoes implementadas */
#include "../include/arvore.h"

void iniciaArvore(ArvoreBin *arvore)
{
    *arvore = NULL;
}

No *criaRaiz(int valor)
{
    No *newNode;

    if ((newNode = alocaNo()) == NULL)
        return NULL;

    newNode->valor = valor;
    newNode->esq = NULL;
    newNode->dir = NULL;

    return newNode;
}

bool arvoreVazia(ArvoreBin arvore)
{
    if (arvore == NULL)
        return true;
    else
        return false;
}

bool insereNoEsquerdo(ArvoreBin arvore, int valor)
{
    No *newNode;

    if (arvore == NULL)
        return false;

    if (arvore->esq != NULL)
        return false;

    if ((newNode = criaRaiz(valor)) == NULL)
        return false;

    arvore->esq = newNode;

    return true;
}

bool insereNoDireito(ArvoreBin arvore, int valor)
{
    No *newNode;

    if (arvore == NULL)
        return false;

    if (arvore->dir != NULL)
        return false;

    if ((newNode = criaRaiz(valor)) == NULL)
        return false;

    arvore->dir = newNode;

    return true;
}

No *noEsquerdo(ArvoreBin arvore) { return arvore->esq; }

No *noDireito(ArvoreBin arvore) { return arvore->dir; }

bool buscaNo(ArvoreBin arvore, int valor)
{
    if (arvoreVazia(arvore))
        return false;

    if (valor == arvore->valor)
        return true;

    else if (buscaNo(noEsquerdo(arvore), valor))
        return true;

    else
        return buscaNo(noDireito(arvore), valor);
}

No *insereNoDeBusca(ArvoreBin abb, int valor)
{
    if (abb == NULL)
        return criaRaiz(valor);

    if (valor < abb->valor)
        abb->esq = insereNoDeBusca(noEsquerdo(abb), valor);

    else // if (valor >= abb->valor)
        abb->dir = insereNoDeBusca(noDireito(abb), valor);

    return abb;
}

int tamanhoDaArvore(ArvoreBin arvore)
{
    if (arvoreVazia(arvore))
        return 0;
    else
        return tamanhoDaArvore(noEsquerdo(arvore)) + 1 + tamanhoDaArvore(noDireito(arvore));
}