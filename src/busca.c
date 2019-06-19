/*
 * Arquivo  : busca.c
 * Tipo     : Complemento de biblioteca 
 *            Contem o corpo das funcoes do arquivo "busca.h"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 - Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem a implementacao e corpo das funcoes 
 *      relacionadas a buscas em array usando a linguagem C,
 *      cuja nomenclatura e descricoes estao localizadas na
 *      biblioteca "busca.h".
 * 
 */

/* Biblioteca (.h) necessaria para as funcoes implementadas */
#include "../include/busca.h"

int buscaBinaria(int *vetor, int tam, int valorBuscado)
{
    int meio, inicio = 0, fim = tam - 1;

    /* Inicia laco de busca pelo elemento */
    while (inicio <= fim)
    {
        /* Calcula a posicao central/meio do vetor */
        meio = inicio + ((fim - inicio) / 2);

        /* verifica se o valor a ser buscado se encontra no meio do vetor... */
        if (vetor[meio] == valorBuscado)
            return meio; // Se sim, retorna a posicao na qual o elemento se encontra.

        else if (valorBuscado > vetor[meio]) // O valor buscado eh maior que o elemento central do vetor?
            /* Se sim, verifica se esta pela direita (na segunda metade do vetor)... */
            inicio = meio + 1;

        else // O valor buscado eh menor que o elemento central do vetor?
             /* Se sim, verifica se esta pela esquerda (na primeira metade do vetor). */
            fim = meio - 1;
    }

    /* caso saia do loop sem retornar, e porque nao foi encontrado em nenhum caso... */
    return -1; // ...entao, retorna -1.
}

int buscaBinariaRecursiva(int *vetor, int inicio, int fim, int valorBuscado)
{
    /* Condicao para recursao: Se o fim for maior ou igual o inicio */
    if (fim >= inicio)
    {
        /* Calcula a posicao central */
        int meio = inicio + ((fim - inicio) / 2);

        /* Se estiver no meio, retorna a posicao */
        if (vetor[meio] == valorBuscado)
            return meio;

        /* Caso contrario, verifica se o valor eh maior que o do meio. Se for, verifica a segunda metade do vetor. */
        if (valorBuscado > vetor[meio])
            return buscaBinariaRecursiva(vetor, meio + 1, fim, valorBuscado);

        /* Se for menor que o elemento do meio, verifica a primeira metade. */
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valorBuscado);
    }

    /* Caso saia das recursoes sem retornar a posicao, retorna -1. */
    return -1;
}

int buscaSequencial(int *vetor, int tam, int valorBuscado)
{
    /* Variavel auxiliar do laco for */
    int i;

    /* Inicia laco de busca pelo elemento percorrendo todo o array */
    for (i = 0; i < tam; i++)
    {
        /* Se o valor na posicao em questao for igual ao valor a ser encontrado... */
        if (vetor[i] == valorBuscado)
            return i; // ... encerra a funcao e o loop retornando a posicao.
    }

    /* caso contrario (caso saia do loop/laco sem retornar nada)... */
    return -1; // ...retorna -1 informando que o valorBuscado nao foi encontrado
}

int buscaSequencialComParada(int *vetor, int tam, int valorBuscado)
{
    /* Variavel auxiliar do laco for */
    int i;

    /* Inicia laco de busca pelo elemento */
    /* Nesse laco de busca se por acaso o elemento na posicao i for maior que o valorBuscado, ele sai na hora do loop sem retornar nada */
    for (i = 0; i < tam && vetor[i] <= valorBuscado; i++)
    {
        /* Se o valor na posicao em questao for igual ao valor a ser encontrado... */
        if (vetor[i] == valorBuscado)
            return i; // ... encerra a funcao e o loop retornando a posicao.
    }

    /* caso saia do loop sem retornar, e porque nao foi encontrado em nenhum caso... */
    return -1; // ...entao, retorna -1.
}

int buscaSequencialSentinela(int *vetor, int tam, int valorBuscado)
{
    /* Inicia as variaveis */
    vetor[tam - 1] = valorBuscado; // Insere o valorBuscado na ultima posicao do array;
    int i = 0;                     // Variavel auxiliar do while que recebera a posicao a ser buscada.

    /* Enquanto o valor da posicao i analisada for diferente do valorBuscado... */
    while (vetor[i] != valorBuscado)
        i++; // ...incrementa o i, buscando na proxima repeticao a proxima posicao.

    /* Se a funcao sair do loop antes de chegar na ultima posicao... */
    if (i < (tam - 1))
        return i; // ...e porque encontrou, entao, retorna a posicao.

    /* Caso contrario, se o loop chegou ate a ultima posicao... */
    else
        return -1; // ...retorna -1 informando que nao encontrou o valorBuscado em outra posicao sem ser a ultima.
}