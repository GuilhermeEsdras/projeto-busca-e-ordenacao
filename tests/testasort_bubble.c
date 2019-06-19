/*
 * Arquivo  : testasort_bubble.c
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

// Para compilar este teste, abra um Terminal (Prompt de Comando/CMD) na pasta raiz do projeto e insira esta linha de comando:
// gcc ./include/sorts.h ./include/geradores.h ./src/sorts.c ./src/geradores.c ./tests/testasort_bubble.c -o bubble

// Apos compilado, para RODAR esse programa execute o nome do programa (bubble) junto com o tamanho do array na frente.
// Exemplo:
// C:\Users\Guilherme\Projeto Busca e Ordenacao\>bubble 10

#include "../include/sorts.h"
#include "../include/geradores.h"

int main(int argc, char *argv[])
{
    int tamDoArray = atoi(argv[1]);

    int arr[tamDoArray]; 
    geraArrayDecrescente(arr, tamDoArray); // Cria array desordenado/decrescente
    // geraArrayAleatorio(arr, tamDoArray); // Cria array desordenado/aleatorio

    printf(" Original: ");
    imprimeArray(arr, tamDoArray); // Printa array desordenado

    bubbleSort(arr, 10); // Ordena usando Bubble Sort!

    printf("\n Ordenado: ");
    imprimeArray(arr, tamDoArray); // Printa array ordenado

    return false;
}