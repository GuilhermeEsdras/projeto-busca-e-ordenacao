/*
 * Arquivo  : geradores.c
 * Tipo     : Complemento de biblioteca 
 *            Contem o corpo das funcoes do arquivo "geradores.h"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 - Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem a implementacao e corpo das funcoes 
 *      relacionadas a geracao de array e criacao de txt usando a linguagem C,
 *      cuja nomenclatura e descricoes estao localizadas na
 *      biblioteca "geradores.h".
 * 
 */

/* Biblioteca (.h) necessaria para as funcoes implementadas */
#include "../include/geradores.h"

bool geraArrayCrescente(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    return true;
}

bool geraArrayDecrescente(int *arr, int n)
{
    int i, pos = 0;
    for (i = n; i > 0; i--)
    {
        arr[pos++] = i;
    }

    return true;
}

bool geraArrayAleatorio(int *arr, int n)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }

    return true;
}

bool arrayParaTXT(int *arr, int n, char *fileName)
{

    strcat(fileName, ".txt");
    printf("Gerando arquivo \"%s\"...\n", fileName);

    FILE *pFile;
    pFile = fopen(fileName, "w");

    if (pFile == NULL)
    {
        printf("Erro ao tentar escrever arquivo! =(\n");
        return NULL;
    }

    printf("Iniciando gravacao...\n");
    int i;
    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
            fprintf(pFile, "%ld\n", arr[i]);
        else
            fprintf(pFile, "%ld", arr[i]);
    }

    printf("Arquivo gerado!\n");
    fclose(pFile);
    return true;
}

void imprimeArray(int *arr, int TAM)
{
    printf("[ ");
    
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("]\n");
}