/******************************************************************************************************
 * TRABALHO IMPLEMENTADO EM DUPLA POR:
 * ANTONIO ERICK FREITAS FERREIRA
 * JOAO PEDRO SOARES MATIAS
*******************************************************************************************************/
#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include "Node.h"

class SparseMatrix{
    private:
    Node *head {nullptr};                               //Iniciando a lista apontando pro sentinela e do sentinela para nullptr em ambos os lados, mas mexerei nisso ao iniciar o construtor;
    int quantLinhas;
    int quantColunas;

    public:

    /*Construtor da classe. Inicializa uma matriz esparsa vazia com capacidade para m
    linhas e n colunas. Essa funcao deve checar se os valores passados sao validos (se
    sao inteiros positivos, ou seja m > 0 e n > 0); se nao forem, uma excecao deve ser
    lancada*/
    SparseMatrix(int m, int n);

    //Destrutor. Libera toda a memória que foi alocada dinamicamente para a matriz.
    ~SparseMatrix();

    

    int getquantLinhas();
    int getquantColunas();
    /*Esta funcao-membro faz o valor na celula (i, j) da matriz ser igual a value, onde i
    é a linha e j é a coluna. Se ja houver um valor nessa posicao, ele e atualizado para
    esse novo valor. Essa funcao deve checar se os ındices i, j passados por parametro
    sao validos; se nao forem validos, uma excecao deve ser lancada.*/
    void insert(int i, int j, double value);


    /*Devolve o valor na celula (i, j) da matriz, onde i e a linha e j e a coluna. Essa
    funcao deve checar se os ındices passados sao validos; se nao forem validos, uma
    excecao deve ser lancada.*/
    double get(int i, int j);


    /*Esta funcao imprime a matriz A no terminal, inclusive os elementos iguais a zero.*/
    void print();
    
};


#endif
