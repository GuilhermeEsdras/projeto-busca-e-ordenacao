/*
 * Arquivo  : arvore.h
 * Tipo     : Header, tambem chamado de: arquivo-interface ou API
 *            Cabecalho/nomenclatura e descricao das funcoes do arquivo arvore.c
 * 
 * Autor        : Guilherme Esdras (guilherme.esdras@academico.ifpb.edu.br)
 * Data         : 06/2019 | Junho de 2019
 * Curso        : Bacharel em Engenharia de Computacao / 2019.1 / Periodo: 2
 * Instituicao  : Instituto Federal de Ciencia e Tecnologia da Paraiba (IFPB) - Campus Campina Grande
 * 
 * Descricao do Arquivo:
 * 
 *      Esse arquivo contem funcoes relacionadas a arvore usando a linguagem C.
 *      As funcoes aqui implementadas permitem ao usuario criar e realizar operacoes 
 *      em uma Arvore Binaria, tanto "convencional" quanto de Busca.
 * 
 */

/* Condicao que impede a bibliteca de ser inclusa mais de uma vez ao compilar 
    garantindo que nao ocorrera erros de importacao durante a compilacao */
#ifndef ARVORE_H
#define ARVORE_H

/* Bibliotecas Padroes Auxiliares */
#include <stdio.h>   // Necessaria para realizar operacoes importantes de entrada e saida de dados
#include <stdlib.h>  // Necessaria para realizar operacoes com alocacao de memoria e ponteiros
#include <string.h>  // Necessaria para manipulacao de Chars
#include <stdbool.h> // Necessaria para usar tipo booleano, true e false

/* Estrutura que define um no de uma arvore  */
typedef struct no
{
    int valor;            // Guarda o dado armazenado por esse No
    struct no *esq, *dir; // Guarda os enderecos dos "filhos" esquerdo e direito desse no
} No;

typedef No *ArvoreBin;

/*
 * Funcao: Inicia Arvore
 * --------------------
 * | Descricao |
 *      Inicia uma Arvore Binaria com valor Nulo.
 * 
 * | Parameters |
 *      *arvore: Endereco de uma Arvore vazia recem definida.
 * 
 * | returns |
 *      Sem retorno. Apenas inicializa a Arvore passada como parametro.
 * 
 * | Exemplo de Uso |
 *      ArvoreBin arv;
 *      iniciaArvore(&arv); // apos essa funcao: arv == NULL
 * 
 */
void iniciaArvore(ArvoreBin *arvore);

/*
 * Funcao: Cria Raiz
 * --------------------
 * | Descricao |
 *      Inicia uma Arvore Binaria com valor Nulo.
 * 
 * | Parameters |
 *      arvore: Ponteiro para uma Arvore VAZIA.
 *      valor: Elemento inteiro a ser definido como raiz desta Arvore
 * 
 * | returns |
 *      No*: Com valor raiz para a Arvore vazia.
 * 
 * | Exemplo de Uso |
 *      Antes dessa funcao: arv == NULL;
 * 
 *      arv = criaRaiz(1);
 * 
 *      Estrutura da arvore "arv" desse exemplo apos essa funcao:
 *              1
 *           /    \
 *         NULL  NULL
 * 
 */
No *criaRaiz(int valor);

/*
 * Funcao: Arvore Vazia
 * --------------------
 * | Descricao |
 *      Verifica se a Arvore Binaria esta vazia.
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria "comum".
 * 
 * | returns |
 *      true: Se estiver vazia
 *      false: Se possuir algum no
 * 
 * | Exemplo de Uso |
 *      Estrutura da arvore "arv" desse exemplo:
 *                  10
 *            /          \
 *          20           30
 *        /   \        /   \
 *      NULL  NULL   NULL  NULL
 * 
 *      arvoreVazia(arv); // return: false
 * 
 */
bool arvoreVazia(ArvoreBin arvore);

/*
 * Funcao: Insere No Esquerdo
 * --------------------
 * | Descricao |
 *      Funcao usada para inserir um filho esquerdo em uma Arvore Binaria Tradicional
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria "comum".
 *      valor: Elemento inteiro a ser inserido
 * 
 * | returns |
 *      true: Se conseguir inserir com sucesso
 *      false: Caso nao possua uma raiz, ou ja possua um no esquerdo ou nao consiga alocar o no
 * 
 * | Exemplo de Uso |
 *      Estrutura inicial da arvore "arv" desse exemplo:
 *              10
 *           /    \
 *        NULL   NULL
 * 
 *      insereNoEsquerdo(arv, 20); // return: true
 * 
 *      Estrutura da arvore apos essa funcao:
 *              10
 *           /    \
 *         20    NULL
 *       /   \
 *    NULL  NULL
 * 
 */
bool insereNoEsquerdo(ArvoreBin arvore, int valor);

/*
 * Funcao: Insere No Direito
 * --------------------
 * | Descricao |
 *      Funcao usada para inserir um filho direito em uma Arvore Binaria Tradicional
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria "comum".
 *      valor: Elemento inteiro a ser inserido
 * 
 * | returns |
 *      true: Se se conseguir inserir com sucesso
 *      false: Caso nao possua uma raiz, ou ja possua um no direito ou nao consiga alocar o no
 * 
 * | Exemplo de Uso |
 *      Estrutura inicial da arvore "arv" desse exemplo:
 *              10
 *           /    \
 *        NULL   NULL
 * 
 *      insereNoDireito(arv, 20); // return: true
 * 
 *      Estrutura da arvore apos essa funcao:
 *              10
 *           /    \
 *        NULL    20
 *              /   \
 *           NULL  NULL
 * 
 */
bool insereNoDireito(ArvoreBin arvore, int valor);

/*
 * Funcao:  No Esquerdo
 * --------------------
 * | Descricao |
 *      Funcao usada para acessar o filho esquerdo de uma Arvore Binaria Tradicional
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria "comum".
 * 
 * | returns |
 *      No*: No esquerdo da Arvore.
 * 
 */
No *noEsquerdo(ArvoreBin arvore);

/*
 * Funcao:  No Direito
 * --------------------
 * | Descricao |
 *      Funcao usada para acessar o filho direito de uma Arvore Binaria Tradicional
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria "comum".
 * 
 * | returns |
 *      No*: No esquerdo da Arvore.
 * 
 */
No *noDireito(ArvoreBin arvore);

/*
 * Funcao: Busca No
 * --------------------
 * | Descricao |
 *      Busca recursivamente um No em uma Arvore Binaria Tradicional
 * 
 * | Parameters |
 *      arvore: Ponteiro pra raiz de uma Arvore Binaria.
 *      valor: Elemento inteiro a ser inserido
 * 
 * | returns |
 *      true: Caso encontre o elemento
 *      false: Caso nao encontre
 * 
 * | Exemplo de Uso |
 *      Estrutura inicial da arvore "arv" desse exemplo:
 *              10
 *           /    \
 *        NULL   NULL
 * 
 *      insereNoDireito(arv, 20); // return: true
 * 
 *      Estrutura da arvore apos essa funcao:
 *              10
 *           /    \
 *        NULL    20
 *              /   \
 *           NULL  NULL
 * 
 */
bool buscaNo(ArvoreBin arvore, int valor);

/*
 * Funcao: Tamanho da Arvore
 * --------------------
 * | Descricao |
 *      Calcula recursivamente o tamanho da arvore 
 * 
 * | Parameters |
 *      abb: Ponteiro pra raiz de uma Arvore Binaria de Busca.
 *      valor: Elemento inteiro a ser inserido
 * 
 * | returns |
 *      Int: Tamanho da arvore
 * 
 * | Exemplo de Uso |
 *      Estrutura inicial da arvore "arv" desse exemplo:
 *                  20
 *            /          \
 *          10           30
 *        /   \        /   \
 *      NULL  NULL   NULL  NULL
 * 
 *      tamanhoDaArvore(arv); // return: 3
 * 
 * 
 */
int tamanhoDaArvore(ArvoreBin arvore);

/*
 * Funcao: Insere No de Busca
 * --------------------
 * | Descricao |
 *      Funcao usada para inserir um no em uma Arvore Binaria de Busca
 * 
 * | Parameters |
 *      abb: Ponteiro pra raiz de uma Arvore Binaria de Busca.
 *      valor: Elemento inteiro a ser inserido
 * 
 * | returns |
 *      No*: Para a folha da arvore
 * 
 * | Exemplo de Uso |
 *      Estrutura inicial da arvore de busca "abb" desse exemplo:
 *                  20
 *            /          \
 *          10           30
 *        /   \        /   \
 *      NULL  NULL   NULL  NULL
 * 
 *      insereNoDeBusca(abb, 15);
 * 
 *      Estrutura da arvore apos essa funcao:
 *                  20
 *            /          \
 *          10           30
 *        /   \        /   \
 *      NULL  15    NULL  NULL
 *          /   \
 *       NULL  NULL
 * 
 */
No *insereNoDeBusca(ArvoreBin abb, int valor);

int maiorValor(ArvoreBin arvore);
int menorValor(ArvoreBin arvore);

/* Usado para encontrar o maior e menor valor respectivamente em uma Arvore Binaria de Busca 
 onde os menores valores se encontram no lado esquerdo da arvore, e os maiores no lado direito da arvore */
int maiorValorBin(ArvoreBin arvore);
int menorValorBin(ArvoreBin arvore);

int buscaPares(ArvoreBin arvore);
int getAltura(ArvoreBin arvore);
int diferencaDeAlturas(ArvoreBin arvore);

int getTamanhoV1(ArvoreBin arvore);
int getTamanhoV2(ArvoreBin arvore);

void imprimePares(ArvoreBin arvore);
void imprimePreOrdem(ArvoreBin arvore);
void imprimeInOrdem(ArvoreBin arvore);
void imprimePosOrdem(ArvoreBin arvore);

/*
 * Funcao auxiliar usada para alocar um No*
 */
No *alocaNo();

#endif
