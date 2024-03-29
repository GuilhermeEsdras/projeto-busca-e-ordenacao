/*
 * Arquivo  : comparators.h
 * Tipo     : Header, tambem chamado de arquivo-interface ou API
 *            Cabecalho e nomenclatura das funcoes do arquivo "comparators.c"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem o cabecalho, nomenclatura e descricao de 
 *      funcoes comparativas usando a linguagem C.
 *      Estas funcoes tem por finalidade servir de parametro para a
 *      funcao de ordenacao qsort(), nativa da linguagem c.
 * 
 */

/* Condicao que impede a bibliteca de ser inclusa mais de uma vez ao compilar 
    garantindo que nao ocorrera erros de importacao durante a compilacao */
#ifndef COMPARATORS_H
#define COMPARATORS_H

/* Bibliotecas Padroes Auxiliares */
#include <stdio.h>   // Necessaria para realizar operacoes importantes de entrada e saida de dados
#include <stdlib.h>  // Necessaria para realizar operacoes com alocacao de memoria e ponteiros
#include <string.h>  // Necessaria para manipulacao de Chars
#include <stdbool.h> // Necessaria para usar tipo booleano, true e false

/*
 * Funcao: Comparador de Inteiros
 * --------------------
 * | Descricao |
 *      Compara dois valores inteiros.
 * 
 * | Parameters |
 *      *a: valor 1 a ser comparado
 *      *b: valor 2 a ser comparado
 * 
 * | returns |
 *      verdadeiro se a for maior que b; falso se b for maior que a; 0 se forem iguais.
 * 
 * | Exemplo de Uso |
 *      int a = 15;
 *      int b = 10;
 *      comparadorDeInt(a, b);
 *      (Return: 5, ou seja, verdadeiro (valor positivo))
 * 
 */
int comparadorDeInt(const void *a, const void *b);

/*
 * Funcao: Comparador de Floats
 * --------------------
 * | Descricao |
 *      Compara dois numeros de ponto flutuante/floats.
 * 
 * | Parameters |
 *      *a: float 1 a ser comparado
 *      *b: float 2 a ser comparado
 * 
 * | returns |
 *       1: se a for maior que b;
 *      -1: se b for maior que a;
 *       0: se forem iguais.
 * 
 * | Exemplo de Uso |
 *      float a = 15.5;
 *      float b = 18.5;
 *      comparadorDeFloat(a, b);
 *      (Return: -1)
 * 
 */
int comparadorDeFloat(const void *a, const void *b);

/*
 * Funcao: Comparador de Caracteres/String
 * --------------------
 * | Descricao |
 *      Compara dois caracteres/strings.
 * 
 * | Parameters |
 *      *a: char 1 a ser comparado
 *      *b: char 2 a ser comparado
 * 
 * | returns |
 *      a: se a for maior que b;
 *      b: se b for maior que a;
 *      a ou b: se forem iguais.
 * 
 * | Exemplo de Uso |
 *      char a = {"abc"};
 *      char b = {"bcd"};
 *      comparadorDeChar(a, b);
 *      (Return: a)
 * 
 */
int comparadorDeChar(const void *a, const void *b);

#endif