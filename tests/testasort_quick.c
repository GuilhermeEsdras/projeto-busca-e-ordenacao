/*
 * Arquivo  : testasort_quick.c
 * Tipo     : Main.
 *            Programa que testa sort
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Programa principal s
 * 
 */

// Para compilar/rodar este teste, abra um Terminal (Prompt de Comando/CMD) na pasta raiz do projeto e insira esta linha de comando:
// gcc ./include/sorts.h ./include/geradores.h ./src/sorts.c ./src/geradores.c ./tests/testasort_quick.c -o quick

#include "../include/sorts.h"
#include "../include/geradores.h"

#define tamDoArray 10 // Quantidade de elementos a serem gerados e ordenados

int main()
{
    int arr[tamDoArray];
    geraArrayDecrescente(arr, tamDoArray); // Cria array desordenado/decrescente
    // geraArrayAleatorio(arr, tamDoArray); // Cria array desordenado/aleatorio

    printf(" Original: ");
    imprimeArray(arr, tamDoArray); // Printa array desordenado

    quickSort(arr, 0, tamDoArray - 1); // Ordena usando Quick Sort!

    printf("\n Ordenado: ");
    imprimeArray(arr, tamDoArray); // Printa array ordenado

    return false;
}