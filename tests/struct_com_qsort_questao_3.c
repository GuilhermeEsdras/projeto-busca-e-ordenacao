#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamNome 41

typedef struct
{
    char nome[tamNome];
    float notas[2];
} Aluno;

int comparadorNotas(const Aluno *a, const Aluno *b)
{
    float media_a = (a->notas[0] + a->notas[1]) / 2;
    float media_b = (b->notas[0] + b->notas[1]) / 2;

    if (media_a - media_b > 0.0)
        return 1;

    else if (media_a - media_b < 0.0)
        return -1;

    return 0;
}

// C:\Users\Guilherme\Documentos\>gcc ./exc/questao3.c -o q3

int main()
{
    int n_alunos;
    scanf("%d", &n_alunos);

    Aluno *alunos;
    alunos = (Aluno *)malloc(sizeof(Aluno) * n_alunos);

    register int i;
    for (i = 0; i < n_alunos; i++)
    {
        scanf("%s %f %f", alunos[i].nome, &alunos[i].notas[0], &alunos[i].notas[1]);
    }

    // printf("- Antes de ordenar pela media:\n");
    // for (i = 0; i < n_alunos; i++)
    // {
    //     printf("Aluno %d - ", i);
    //     printf("Nome: [ %s ], Nota 1: [ %.2f ], Nota 2: [ %.2f ] \n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1]);
    // }

    qsort(alunos, n_alunos, sizeof(Aluno), (void *)comparadorNotas);

    //printf("- Apos ordenar (crescentemente) pela media:\n");
    // for (i = 0; i < n_alunos; i++)
    // {
    //     printf("Aluno %d - ", i);
    //     printf("Nome: [ %s ], Nota 1: [ %.2f ], Nota 2: [ %.2f ] \n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1]);
    // }

    for (i = 0; i < n_alunos; i++)
    {
        printf("%s\n", alunos[i].nome);
    }

    return 0;
}