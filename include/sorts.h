/*
 * Arquivo  : sorts.h
 * Tipo     : Header, tambem chamado de: arquivo-interface ou API
 *            Cabecalho/nomenclatura e descricao das funcoes do arquivo "sorts.c"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem o cabecalho, nomenclatura e descricao de 
 *      funcoes relacionadas a ordenacao usando a linguagem C.
 *      As funcoes aqui implementadas permitem ao usuario ordenar 
 *      um array de elementos.
 * 
 */

/* Condicao que impede a bibliteca de ser inclusa mais de uma vez ao compilar 
    garantindo que nao ocorrera erros de importacao durante a compilacao */
#ifndef SORTS_H
#define SORTS_H

/* Bibliotecas Padroes Auxiliares */
#include <stdio.h>   // Necessaria para realizar operacoes importantes de entrada e saida de dados
#include <stdlib.h>  // Necessaria para realizar operacoes com alocacao de memoria e ponteiros
#include <string.h>  // Necessaria para manipulacao de Chars
#include <stdbool.h> // Necessaria para usar tipo booleano, true e false

/*
 * Funcao: Insertion Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Insertion Sort.
 *      Insertion Sort, ou ordenação por inserção, é o algoritmo de ordenação que, 
 *      dado uma estrutura (array, lista) constrói uma matriz final com um elemento
 *      de cada vez, uma inserção por vez. (wikipedia.org/wiki/Insertion_sort)
 * 
 * | Complexidade |
 *      Melhor caso : O(n) // Quando o array ja esta ordenado
 *      Caso medio  : (N²)/4 -> O(N²) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(N²) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      tam: Tamanho do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      insertionSort(arr, 10);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void insertionSort(int *vetor, int tam);

/*
 * Funcao: Merge Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Merge Sort ou Ordenacao por Mistura.
 *      Sua ideia básica consiste em Dividir (o problema em vários subproblemas e 
 *      resolver esses subproblemas através da recursividade) e Conquistar 
 *      (após todos os subproblemas terem sido resolvidos ocorre a conquista que é 
 *      a união das resoluções dos subproblemas). (wikipedia.org/wiki/Merge_sort)
 * 
 * | Complexidade |
 *      Melhor caso : O(nlogn) // Quando o array ja esta ordenado
 *      Caso medio  : O(nlogn) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(nlogn) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      inicio: Posicao inicial do array
 *      fim: Posicao final do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      mergeSort(arr, 0, 9);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void mergeSort(int *vetor, int inicio, int fim);
/* Funcao Auxiliar do Merge Sort */
void merge(int *vetor, int inicio, int meio, int fim);

/*
 * Funcao: Bubble Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Bubble Sort.
 *      O bubble sort, ou ordenação por flutuação (literalmente "por bolha"), 
 *      é um algoritmo de ordenação dos mais simples. A ideia é percorrer o vector 
 *      diversas vezes, e a cada passagem fazer flutuar para o topo o maior elemento 
 *      da sequência. (wikipedia.org/wiki/Bubble_sort)
 * 
 * | Complexidade |
 *      Melhor caso : O(n) // Quando o array ja esta ordenado
 *      Caso medio  : O(n²) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(n²) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      tam: Tamanho do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      bubbleSort(arr, 10);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void bubbleSort(int *vetor, int tam);

/*
 * Funcao: Selection Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Selection Sort.
 *      A ordenação por seleção (do inglês, selection sort) é um algoritmo de ordenação 
 *      baseado em se passar sempre o menor valor do vetor para a primeira posição (ou 
 *      o maior dependendo da ordem requerida), depois o de segundo menor valor para a 
 *      segunda posição, e assim é feito sucessivamente com os n-1 elementos restantes, 
 *      até os últimos dois elementos. (wikipedia.org/wiki/Selection_sort)
 * 
 * | Complexidade |
 *      Melhor caso : O(n²) // Quando o array ja esta ordenado
 *      Caso medio  : O(n²) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(n²) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      tam: Tamanho do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      selectionSort(arr, 10);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void selectionSort(int *vetor, int tam);

/*
 * Funcao: Quick Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Quick Sort.
 *      O quicksort adota a estratégia de divisão e conquista. A estratégia consiste em 
 *      rearranjar as chaves de modo que as chaves "menores" precedam as chaves "maiores".
 *      Em seguida o quicksort ordena as duas sublistas de chaves menores e maiores 
 *      recursivamente até que a lista completa se encontre ordenada.
 *      (wikipedia.org/wiki/Quicksort)
 * 
 * | Complexidade |
 *      Melhor caso : O(n²) // Quando o array ja esta ordenado
 *      Caso medio  : O(nlogn) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(nlogn) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      inicio: Posicao inicial do array
 *      fim: Posicao final do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      quickSort(arr, 0, 9);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void quickSort(int *vetor, int inicio, int fim);

/*
 * Funcao: Heap Sort
 * --------------------
 * | Descricao |
 *      Ordena um array de inteiros usando o algoritmo Heap Sort.
 *      O heapsort utiliza uma estrutura de dados chamada heap, para ordenar os elementos
 *      à medida que os insere na estrutura. Assim, ao final das inserções, os elementos
 *      podem ser sucessivamente removidos da raiz da heap, na ordem desejada, lembrando-se
 *      sempre de manter a propriedade de max-heap. (wikipedia.org/wiki/Heapsort)
 * 
 * | Complexidade |
 *      Melhor caso : O(nlogn) // Quando o array ja esta ordenado
 *      Caso medio  : O(nlogn) // Quando o array possui valores aleatorios desordenados
 *      Pior caso   : O(nlogn) // Quando o array esta ordenado inversamente
 * 
 * | Parameters |
 *      *vetor: Array a ser ordenado
 *      tam: Tamanho do array
 * 
 * | returns |
 *      Nao ha retorno. Apenas ordena o array.
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [4, 8, 3, 5, 1, 2, 9, 0, 6, 7];
 *      heapSort(arr, 10);
 *      (arr == [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
 * 
 */
void heapSort(int *vetor, int tam);

#endif