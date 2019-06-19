/*
 * Arquivo  : testa_arvores.c
 * Tipo     : Main.
 *            Programa que testa as funcoes da biblioteca "arvore.h"
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Programa principal sobre Arvore Binaria.
 *      Usado para testar funcoes da biblioteca "Arvore.h"
 * 
 */

// gcc ./tests/testa_arvores.c ./include/arvore.h ./src/arvore.c -o tarv

#include "../include/arvore.h"


/* Header de Funcoes Locais */
int getOpcao();


/* Main */
int main() {


    return false;
}


// int main(int argc, char *argv[])
// {
//     int opcao = getOpcao();

//     printf("Opcao: %d", opcao);

//     return false;
// }


/* Funcoes Locais */
int getOpcao()
{
    int op;

    while (true)
    {
        printf("Selecione o tipo de Arvore:\n"
               "    1- Arvore Binaria\n"
               "    2- Arvore Binaria de Busca\n"
               "        Opcao: ");
        scanf("%d", &op);

        if (op == 1 || op == 2)
            return op;

        else
            printf("Opcao invalida!\n");
    }
}