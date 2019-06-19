/*
 * Arquivo  : sorts.c
 * Tipo     : Complemento de biblioteca 
 *            Contem o corpo das funcoes do arquivo "sorts.h"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 - Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem a implementacao e corpo das funcoes 
 *      relacionadas a ordenacao de array usando a linguagem C,
 *      cuja nomenclatura e descricoes estao localizadas na
 *      biblioteca "sorts.h".
 * 
 */

/* Biblioteca (.h) necessaria para as funcoes implementadas */
#include "../include/sorts.h"

void insertionSort(int *vetor, int tam)
{
    /* Inicia as variaveis necessarias */
    int pos, ant, aux;

    /* O loop comeca em 1 pois o primeiro elemento ja esta naturalmente ordenado */
    for (pos = 1; pos < tam; pos++)
    {
        aux = vetor[pos]; // Auxiliar que armazena o valor da posicao atual que esta sendo verificado
        ant = (pos - 1);  // Posicao anterior

        /* Ira se repetir enquanto houver elementos maiores que o elemento atual */
        while (ant >= 0 && aux < vetor[ant])
        {
            /* Se o elemento da posicao de tras for maior que o da frente, */
            vetor[ant + 1] = vetor[ant]; // transfere o elemento de tras para a posicao da frente
            ant--;                       // Decrementa para verificar o anterior do anterior
        }

        /* Quando sair do loop, a variavel ant estara na posicao de atras dos maiores que o elemento verificado, entao... */
        vetor[ant + 1] = aux; // ... passa o elemento verificado para tras dos maiores que ele (caso houver)
    }
}

void mergeSort(int *vetor, int inicio, int fim)
{
    /* Divide o array e depois ordenada, recursivamente */
    if (inicio < fim)
    {
        int meio = (fim + inicio) / 2; // Define a posicao central/meio

        mergeSort(vetor, inicio, meio);    // Divide a primeira metade (Do inicio pro meio)
        mergeSort(vetor, (meio + 1), fim); // Divide a segunda metade (Do meio pro fim)
        merge(vetor, inicio, meio, fim);   // Combina as duas metades de forma ordenada
    }

    /* Condicao de parada para a recursao: */
    /* Caso o inicio seja maior ou igual ao fim, ou seja, possua apenas um elemento, retorna a funcao */
    else
        return;
}

void merge(int *vetor, int inicio, int meio, int fim)
{
    /* Inicia as variaveis que guardarao a posicao do array do inicio pro meio e do meio pro fim */
    int posiDoInicioProMeio = inicio, posiDoMeioProFim = meio + 1;

    /* Cria um vetor auxiliar que guardara os elementos ordenados para depois transferir ao original */
    int tamDoAux = (fim - inicio + 1);
    int *vetorAux = (int *)malloc(sizeof(int) * tamDoAux);
    int posicoesDoAux = 0;

    /* Loop que percorre as duas metades do array comparando o elemento de uma metade com o da outra */
    while (posiDoInicioProMeio <= meio && posiDoMeioProFim <= fim)
    {
        /* Verifica separadamente se os elementos da primeira metade sao maiores que o da segunda e vice-versa, um por um */
        if (vetor[posiDoInicioProMeio] < vetor[posiDoMeioProFim])
            vetorAux[posicoesDoAux] = vetor[posiDoInicioProMeio++]; // Caso seja, insere no vetor auxiliar e incrementa/passa para o proximo

        else
            vetorAux[posicoesDoAux] = vetor[posiDoMeioProFim++]; // Caso seja, insere no vetor auxiliar e incrementa/passa para o proximo

        posicoesDoAux++; // Passa para a proxima posicao do vetor auxiliar
    }

    /* Verifica se restaram elementos na primeira metade. Em caso positivo, os insere no vetor auxiliar */
    while (posiDoInicioProMeio <= meio)
        vetorAux[posicoesDoAux++] = vetor[posiDoInicioProMeio++];

    /* Verifica se restaram elementos na segunda metade. Em caso positivo, os insere no vetor auxiliar */
    while (posiDoMeioProFim <= fim)
        vetorAux[posicoesDoAux++] = vetor[posiDoMeioProFim++];

    /* Transfere os elementos do vetor auxiliar para o vetor original */
    for (posicoesDoAux = inicio; posicoesDoAux <= fim; posicoesDoAux++)
        vetor[posicoesDoAux] = vetorAux[posicoesDoAux - inicio];

    /* Libera o array auxiliar */
    free(vetorAux);
}

void bubbleSort(int *vetor, int tam)
{
    /* Inicia as variaveis necessarias */
    int i, j, aux;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int *vetor, int tam)
{
    /* Inicia as variaveis necessarias */
    int i, j, min, aux;

    for (i = 0; i < (tam - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < tam; j++)
        {
            if (vetor[j] < vetor[min])
                min = j;
        }

        if (vetor[i] != vetor[min])
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

void quickSort(int *vetor, int inicio, int fim)
{
    /* Inicia as variaveis necessarias */
    int i = inicio, j = fim, pivot = vetor[(inicio + fim) / 2], aux;

    while (i <= j)
    {
        while (vetor[i] < pivot && i < fim)
            i++;
        while (vetor[j] > pivot && j > inicio)
            j--;

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i++] = vetor[j];
            vetor[j--] = aux;
        }
    }

    if (j > inicio)
        quickSort(vetor, inicio, j + 1);

    if (i < fim)
        quickSort(vetor, i, fim);
}

void heapSort(int *vetor, int tam)
{
    /* Inicia as variaveis necessarias */
    int i = tam / 2, pai, filho, t;

    while (true)
    {
        if (i > 0)
            t = vetor[--i];

        else
        {
            tam--;
            if (tam == 0)
                return;
            t = vetor[tam];
            vetor[tam] = vetor[0];
        }

        pai = i;
        filho = (i * 2 + 1);
        while (filho < tam)
        {
            if ((filho + 1 < tam) && (vetor[filho + 1] > vetor[filho]))
                filho++;

            if (vetor[filho] > t)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = (pai * 2 + 1);
            }
            else
                break;
        }

        vetor[pai] = t;
    }
}