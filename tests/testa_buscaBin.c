/*
 * Arquivo  : testa_buscaBin.c
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

// gcc ./include/busca.h ./src/busca.c ./include/sorts.h ./src/sorts.c ./include/geradores.h ./src/geradores.c ./tests/testa_buscaBin.c -o tbb

#include "../include/busca.h"
#include "../include/sorts.h"
#include "../include/geradores.h"

int comparadorDeInt(const void *a, const void *b);

int main(int argc, char *argv[])
{
    int *array, tam, valorBuscado;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);

    array = (int *)malloc(sizeof(int) * tam);

    int op1, op2;

    while (true)
    {
        printf("Opcoes:\n"
               "   [1] - Gerar um Array Automaticamente\n"
               "   [2] - Digitar os Elementos do Array\n"
               "   [0] - Sair\n"
               "       Opcao: ");
        scanf("%d", &op1);
        if (op1 < 0 || op1 > 2)
            printf("Opcao invalida!\n");
        else
            break;
    }

    switch (op1)
    {
        case 0:
            printf("Saindo...\n");
            exit(EXIT_SUCCESS);

        case 1:
            while (true)
            {
                printf("Tipo de Array:\n"
                    "   [1] - Array Aleatorio\n"
                    "   [2] - Array Decrescente\n"
                    "   [0] - Sair\n"
                    "       Opcao: ");
                scanf("%d", &op2);
                if (op2 < 0 || op2 > 2)
                    printf("Opcao invalida!\n");
                else
                    break;
            }

            switch (op2)
            {
                case 0:
                    printf("Saindo...\n");
                    exit(EXIT_SUCCESS);

                case 1:
                    if (geraArrayAleatorio(array, tam))
                        printf("Array Aleatorio gerado!\n");
                    break;

                case 2:
                    if (geraArrayDecrescente(array, tam))
                        printf("Array gerado!\n");
                    break;

                default:
                    break;
            }

            break;

        case 2:
            printf("Digite os elementos do array separados por espaco:\n");
            int i;
            for (i = 0; i < tam; i++)
            {
                scanf("%d", &array[i]);
            }
            break;

        default:
            break;
    }

    printf("Array antes de ordenar: ");
    imprimeArray(array, tam);

    qsort(array, tam, sizeof(int), comparadorDeInt);

    printf("Array apos ordenar: ");
    imprimeArray(array, tam);

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &valorBuscado);

    int tipo_busca;
    while (true)
    {
        printf("Digite o tipo de busca que deseja usar:\n"
               "   [1] - Busca Binaria\n"
               "   [2] - Busca Binaria Recursiva\n"
               "   [3] - Busca Sequencial\n"
               "   [4] - Busca Sequencial com Parada\n"
               "   [0] - Sair\n"
               "       Opcao: ");
        scanf("%d", &tipo_busca);
        if (tipo_busca < 0 || tipo_busca > 4)
            printf("Opcao invalida!\n");
        else
            break;
    }

    int pos;
    switch (tipo_busca)
    {
        case 0:
            printf("Saindo...\n");
            exit(EXIT_SUCCESS);

        case 1:
            pos = buscaBinaria(array, tam, valorBuscado);
            break;

        case 2:
            pos = buscaBinariaRecursiva(array, 0, tam - 1, valorBuscado);
            break;

        case 3:
            pos = buscaSequencial(array, tam, valorBuscado);
            break;

        case 4:
            pos = buscaSequencialComParada(array, tam, valorBuscado);
            break;

        default:
            break;
    }

    (pos >= 0) ? printf("Elemento encontrado! Posicao: %d.\n", pos) : printf("Elemento nao encontrado!\n");

    return false;
}

int comparadorDeInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}