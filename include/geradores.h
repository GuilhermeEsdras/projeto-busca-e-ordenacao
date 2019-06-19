/*
 * Arquivo  : geradores.h
 * Tipo     : Header, tambem chamado de: arquivo-interface ou API
 *            Cabecalho/nomenclatura e descricao das funcoes do arquivo "geradores.c"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem o cabecalho, nomenclatura e descricao de 
 *      funcoes relacionadas a geracao de Arrays e .TXT usando a linguagem C.
 *      As funcoes aqui implementadas permitem ao usuario gerar e imprimir
 *      vetores de elementos com valores aleatorios, e passa-los para um arquivo de text (.TXT).
 * 
 */

/* Condicao que impede a bibliteca de ser inclusa mais de uma vez ao compilar 
    garantindo que nao ocorrera erros de importacao durante a compilacao */
#ifndef GERADORES_H
#define GERADORES_H

/* Bibliotecas Padroes Auxiliares */
#include <stdio.h>   // Necessaria para realizar operacoes importantes de entrada e saida de dados
#include <stdlib.h>  // Necessaria para realizar operacoes com alocacao de memoria e ponteiros
#include <string.h>  // Necessaria para manipulacao de Chars
#include <stdbool.h> // Necessaria para usar tipo booleano, true e false
#include <time.h>    // Necessaria para relizar operacoes com influencia do tempo

/* .::Gera Array Crescente::.
 * -------------------
 *  arr: Ponteiro para um array vazio
 *  n: Numero de elementos a serem criados em ordem crescente (de 1 a n) e colocados neste array
 *  returns: true se conseguir, false caso contrario
 */
bool geraArrayCrescente(int *arr, int n);

/* .::Gera Array Decrescente::.
 * -------------------
 *  arr: Ponteiro para um array vazio
 *  n: Numero de elementos a serem criados em ordem decrescente (de n a 1) e colocados neste array
 *  returns: true se conseguir, false caso contrario
 */
bool geraArrayDecrescente(int *arr, int n);

/* .::Gera Array Aleatorio::.
 * -------------------
 *  arr: Ponteiro para um array vazio
 *  n: Numero de elementos a serem criados aleatoriamente e colocados neste array
 *  returns: true se conseguir, false caso contrario
 */
bool geraArrayAleatorio(int *arr, int n);

/* .::array Para TXT::.
 * -------------------
 *  int* arr: Ponteiro para o array na qual contem os elementos a serem transferidos para o .txt
 *  int n: Tamanho do array
 *  fileName: Nome do arquivo .txt a ser criado (Obs.: Nao e necessario colocar a extensao ".txt" no nome))
 *  returns: true se der tudo certo ou false se der algo errado
 */
bool arrayParaTXT(int *arr, int n, char *fileName);

void imprimeArray(int *arr, int TAM);

#endif