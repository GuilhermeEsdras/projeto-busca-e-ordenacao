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

    else if (buscaNo(noEsquerdo(arvore), valor)) // a mesma coisa que: buscaNo(arvore->esq, valor)
        return true;

    else
        return buscaNo(noDireito(arvore), valor); // a mesma coisa que: buscaNo(arvore->dir, valor)
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

int maiorValor(ArvoreBin arvore)
{
    if (arvore == NULL)
        return 0;

    int res = arvore->valor;
    int lres = maiorValor(arvore->esq);
    int rres = maiorValor(arvore->dir);

    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int menorValor(ArvoreBin arvore)
{
    if (arvore == NULL)
        return 0;

    int res = arvore->valor;
    int lres = maiorValor(arvore->esq);
    int rres = maiorValor(arvore->dir);

    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}

int maiorValorBin(ArvoreBin arvore)
{
    ArvoreBin atual = arvore;

    while (atual->dir != NULL)
        atual = atual->dir;

    return atual->valor;
}

int menorValorBin(ArvoreBin arvore)
{
    ArvoreBin atual = arvore;

    while (atual->esq != NULL)
        atual = atual->esq;

    return atual->valor;
}

int buscaPares(ArvoreBin arvore)
{
    int num = 0;

    if (arvore == NULL)
        return num;

    if (arvore->valor % 2 == 0)
        num = 1;

    return buscaPares(arvore->esq) + num + buscaPares(arvore->dir);
}

int tamanhoDaArvore(ArvoreBin arvore)
{
    if (arvoreVazia(arvore)) // ou: if (arvore == NULL)
        return 0;
    else
        return tamanhoDaArvore(noEsquerdo(arvore)) + 1 + tamanhoDaArvore(noDireito(arvore));
}

int getAltura(ArvoreBin arvore)
{
    if (arvore == NULL)
        return 0;

    int left = getAltura(arvore->esq);
    int right = getAltura(arvore->dir);

    if (left > right)
        return 1 + left;

    else
        return 1 + right;
}

int diferencaDeAlturas(ArvoreBin arvore) {
    int altura_esquerda = getAltura(arvore->esq) +1;
    int altura_direita = getAltura(arvore->dir) +1;

    int maior = 0;
    int menor = 0;

    if (altura_esquerda > altura_direita) {
        maior = altura_esquerda;
        menor = altura_direita;
    }

    else {
        maior = altura_direita;
        menor = altura_esquerda;
    }

    return maior - menor;
}

int getTamanhoV1(ArvoreBin arvore)
{
    if (arvore == NULL)
        return 0;
    else
        return (1 + getTamanhoV1(arvore->esq) + getTamanhoV1(arvore->dir));
}

int getTamanhoV2(ArvoreBin arvore)
{
    if (arvore == NULL)
        return 0;

    int tamEsq = getTamanhoV2(arvore->esq);
    int tamDir = getTamanhoV2(arvore->dir);

    return 1 + tamEsq + tamDir;
}

void imprimePares(ArvoreBin arvore) {
    if (!arvoreVazia(arvore)) {
        if (arvore->valor % 2 == 0) {
            printf("[ %d ] ", arvore->valor);
        }
        imprimePares(noEsquerdo(arvore));
        imprimePares(noDireito(arvore));
    }
}

void imprimePreOrdem(ArvoreBin arvore)
{
    if (!arvoreVazia(arvore))
    {
        printf("[ %d ] ", arvore->valor);
        imprimePreOrdem(noEsquerdo(arvore));
        imprimePreOrdem(noDireito(arvore));
    }
}

void imprimeInOrdem(ArvoreBin arvore)
{
    if (!arvoreVazia(arvore))
    {
        imprimeInOrdem(noEsquerdo(arvore));
        printf("[ %d ] ", arvore->valor);
        imprimeInOrdem(noDireito(arvore));
    }
}

void imprimePosOrdem(ArvoreBin arvore)
{
    if (!arvoreVazia(arvore))
    {
        imprimePosOrdem(noEsquerdo(arvore));
        imprimePosOrdem(noDireito(arvore));
        printf("[ %d ] ", arvore->valor);
    }
}

No *alocaNo() { return (No *)malloc(sizeof(No)); }