#include "../include/arvore.h"

// gcc ./include/arvore.h ./src/arvore.c ./tests/arvore_pares.c -o arpares

int main()
{

    ArvoreBin a;
    iniciaArvore(&a);

    if (arvoreVazia(a))
        printf("Arvore vazia!\n");

    a = criaRaiz(10);

    insereNoDeBusca(a, 8);
    insereNoDeBusca(a, 9);
    insereNoDeBusca(a, 6);
    insereNoDeBusca(a, 7);
    insereNoDeBusca(a, 4);
    insereNoDeBusca(a, 20);
    insereNoDeBusca(a, 25);
    insereNoDeBusca(a, 17);
    insereNoDeBusca(a, 30);
    insereNoDeBusca(a, 12);
    insereNoDeBusca(a, 11);

    printf("\n Pre Ordem: ");
    imprimePreOrdem(a);
    printf("\n In Ordem: ");
    imprimeInOrdem(a);
    printf("\n Pos Ordem: ");
    imprimePosOrdem(a);

    printf("\n");
    printf("|Informacoes da arvore|");
    printf("\nNumero 4 existe? %s", buscaNo(a, 4) ? "Sim" : "Nao");
    printf("\nNumero 5 existe? %s", buscaNo(a, 5) ? "Sim" : "Nao");
    printf("\nNos Pares: ");
    imprimePares(a);
    printf("\nQuantidade de Nos Pares: %d", buscaPares(a));
    printf("\nTamanho da Arvore (Quantidade de nos) [V1]: %d", getTamanhoV1(a));
    printf("\nTamanho da Arvore (Quantidade de nos) [V2]: %d", getTamanhoV2(a));
    printf("\nAltura da Arvore: %d", getAltura(a));
    printf("\nAltura da Arvore Esquerda: %d", getAltura(a->esq) + 1);
    printf("\nAltura da Arvore Direita: %d", getAltura(a->dir) + 1);
    printf("\nDiferenca de alturas: %d", diferencaDeAlturas(a));

    return false;
}