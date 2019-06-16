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

int buscaBinaria(long int *vetor, long int tam, long int valorBuscado)
{
    /* inicia as variaveis */
    long int meio, inicio = 0, fim = (tam - 1);

    /* Inicia laco de busca pelo elemento */
    while (inicio <= fim)
    {
        /* define a posicao central/meio do vetor */
        meio = (inicio + fim) / 2;

        /* verifica se o valor a ser buscado se encontra no meio do vetor... */
        if (vetor[meio] == valorBuscado)
            return meio; // Se sim, retorna a posicao na qual o elemento se encontra.

        /* ...caso contrario, verifica se esta pela esquerda... */
        else if (vetor[meio] < valorBuscado)
            inicio = (meio + 1);

        /* ...caso contrario, verifica se esta pela direita. */
        else
            fim = (meio + 1);
    }

    /* caso saia do loop sem retornar, e porque nao foi encontrado em nenhum caso... */
    return -1; // ...entao, retorna -1.
}

int buscaBinariaRecursiva(long int *vetor, long int inicio, long int fim, long int valorBuscado)
{
    /* Define a posicao central (meio) do array */
    long int meio = (inicio + fim) / 2;

    /* Condicao de parada 1 (Caso encontre): Se o valorBuscado se encontra nessa posicao... */
    if (vetor[meio] == valorBuscado)
        return meio; // ...retorna a posicao

    /* Condicao de parada 2 (Caso nao encontre): Se ja nao existem mais posicoes a serem verificadas... */
    if (inicio >= fim)
        return -1; // ...retorna -1

    /* Caso nao entre em nenhum dos casos de parada anteriores... */
    else if (vetor[meio] < valorBuscado)
        return buscaBinariaRecursiva(vetor, (meio + 1), fim, valorBuscado); // ...busca recursivamente pela esquerda
    else
        return buscaBinariaRecursiva(vetor, inicio, (fim + 1), valorBuscado); // ...busca recursivamente pela direita
}

int buscaSequencial(long int *vetor, long int tam, long int valorBuscado)
{
    /* Variavel auxiliar do laco for */
    long int i;

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

int buscaSequencialSentinela(long int *vetor, long int tam, long int valorBuscado)
{
    /* Inicia as variaveis */
    vetor[tam] = valorBuscado; // Insere o valorBuscado na ultima posicao do array;
    long int i = 0;            // Variavel auxiliar do while que recebera a posicao a ser buscada.

    /* Enquanto o valor da posicao i analisada for diferente do valorBuscado... */
    while (vetor[i] != valorBuscado)
        i++; // ...incrementa o i, buscando na proxima repeticao a proxima posicao.

    /* Se a funcao sair do loop antes de chegar na ultima posicao... */
    if (i < tam)
        return i; // ...e porque encontrou, entao, retorna a posicao.

    /* Caso contrario, se o loop chegou ate a ultima posicao... */
    else
        return -1; // ...retorna -1 informando que nao encontrou o valorBuscado em outra posicao sem ser a ultima.
}

int buscaSequencialComParada(long int *vetor, long int tam, long int valorBuscado)
{
    /* Variavel auxiliar do laco for */
    long int i;

    /* Inicia laco de busca pelo elemento */
    for (i = 0; i < tam && vetor[i] <= valorBuscado; i++)
    {
        /* Se o valor na posicao em questao for igual ao valor a ser encontrado... */
        if (vetor[i] == valorBuscado)
            return i; // ... encerra a funcao e o loop retornando a posicao.
    }
    
    /* caso saia do loop sem retornar, e porque nao foi encontrado em nenhum caso... */
    return -1; // ...entao, retorna -1.
}
