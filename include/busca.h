/*
 * Arquivo  : busca.h
 * Tipo     : Header, tambem chamado de: arquivo-interface ou API
 *            Cabecalho/nomenclatura e descricao das funcoes do arquivo "busca.c"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem o cabecalho, nomenclatura e descricao de 
 *      funcoes relacionadas a buscas usando a linguagem C.
 *      As funcoes aqui implementadas permitem ao usuario buscar 
 *      um determinado valor dentro de um array de elementos ORDENADOS.
 * 
 */

/* Condicao que impede a bibliteca de ser inclusa mais de uma vez ao compilar 
    garantindo que nao ocorrera erros de importacao durante a compilacao */
#ifndef BUSCA_H
#define BUSCA_H

/* Bibliotecas Padroes Auxiliares */
#include <stdio.h>   // Necessaria para realizar operacoes importantes de entrada e saida de dados
#include <stdlib.h>  // Necessaria para realizar operacoes com alocacao de memoria e ponteiros
#include <string.h>  // Necessaria para manipulacao de Chars
#include <stdbool.h> // Necessaria para usar tipo booleano, true e false

/*
 * Funcao: Busca Binaria
 * --------------------
 * | Descricao |
 *      Busca um determinado valor dentro de um array.
 * 
 * | Parameters |
 *      *vetor: Array de elementos a ser vasculhado
 *      tam: Tamanho do array
 *      valorBuscado: Valor a ser buscado dentro deste array
 * 
 * | returns |
 *      Posicao do elemento buscado (caso seja encontrado), 
 *      ou -1 caso nao seja encontrado
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
 *      buscaBinaria(arr, 10, 5);
 *      (Return: 4)
 * 
 */
int buscaBinaria(int *vetor, int tam, int valorBuscado);

/*
 * Funcao: Busca Binaria Recursiva
 * --------------------
 * | Descricao |
 *      Busca um determinado valor dentro de um array de forma recursiva.
 * 
 * | Parameters |
 *      *vetor: Array de elementos a ser vasculhado
 *      inicio: Primeira posicao do array
 *      fim: Ultima posicao do array
 *      valorBuscado: Valor a ser buscado dentro deste array
 * 
 * | returns |
 *      Posicao do elemento buscado (caso seja encontrado), 
 *      ou -1 caso nao seja encontrado
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
 *      buscaBinariaRecursiva(arr, 0, 9, 5);
 *      (Return: 4)
 * 
 */
int buscaBinariaRecursiva(int *vetor, int inicio, int fim, int valorBuscado);

/*
 * Funcao: Busca Sequencial
 * --------------------
 * | Descricao |
 *      Busca um determinado valor dentro de um array vasculhando todo o array
 *      de forma sequencial.
 * 
 * | Complexidade |
 *      Melhor caso : O(1) // Quando o valor a ser buscado esta na primeira posicao do array
 *      Caso medio  : (N+1)/2 -> O(N) // Quando o valor a ser buscado esta pelo meio do array
 *      Pior caso   : O(N) // Quando o valor a ser buscaso esta na ultima posicao do array
 * 
 * | Parameters |
 *      *vetor: Array de elementos a ser vasculhado
 *      tam: Tamanho do array
 *      valorBuscado: Valor a ser buscado dentro deste array
 * 
 * | returns |
 *      Posicao do elemento buscado (caso seja encontrado), 
 *      ou -1 caso nao seja encontrado
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
 *      buscaSequencial(arr, 10, 5);
 *      (Return: 4)
 * 
 */
int buscaSequencial(int *vetor, int tam, int valorBuscado);

/*
 * Funcao: Busca Sequencial com Parada
 * --------------------
 * | Descricao |
 *      Busca um determinado valor dentro de um array.
 *      Forma otimizada da busca sequencial.
 *      Encerra a funcao caso o valor analisado seja maior que o valorBuscado.
 *      Nao altera a complexidade do algoritmo, mas impede que todo o array seja
 *      buscado sem necessidade, caso algum valor maior que o procurado 
 *      seja encontrado antes.
 * 
 * | Parameters |
 *      *vetor: Array de elementos a ser vasculhado
 *      tam: Tamanho do array
 *      valorBuscado: Valor a ser buscado dentro deste array
 * 
 * | returns |
 *      Posicao do elemento buscado (caso seja encontrado), 
 *      ou -1 caso nao seja encontrado
 * 
 * | Exemplo de Uso |
 *      int arr[10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
 *      buscaSequencialComParada(arr, 10, 5);
 *      (Return: 4)
 * 
 */
int buscaSequencialComParada(int *vetor, int tam, int valorBuscado);

/*
 * Funcao: Busca Sequencial Sentinela
 * --------------------
 * | Descricao |
 *      Busca um determinado valor dentro de um array.
 *      Forma otimizada da busca sequencial.
 *      E necessario que o array possua uma posicao vazia no final.
 *      Nao altera a complexidade do algoritmo, mas melhora a velocidade de busca
 *      retirando a comparacao de dentro do laco.
 * 
 * | Parameters |
 *      *vetor: Array de elementos a ser vasculhado
 *      tam: Tamanho do array
 *      valorBuscado: Valor a ser buscado dentro deste array
 * 
 * | returns |
 *      Posicao do elemento buscado (caso seja encontrado), 
 *      ou -1 caso nao seja encontrado
 * 
 * | Exemplo de Uso |
 *      int arr[11] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0]; // A ultima posicao do array deve estar vazia nesse tipo de busca
 *      buscaSequencialSentinela(arr, 11, 5);
 *      (Return: 4)
 * 
 */
int buscaSequencialSentinela(int *vetor, int tam, int valorBuscado);

#endif