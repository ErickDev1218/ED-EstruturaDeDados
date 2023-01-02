/******************************************************************************************************
 * TRABALHO IMPLEMENTADO EM DUPLA POR:
 * ANTONIO ERICK FREITAS FERREIRA
 * JOAO PEDRO SOARES MATIAS
*******************************************************************************************************/
#ifndef NODE_H
#define NODE_h

struct Node{
    Node *direita{nullptr};
    Node *abaixo{nullptr};
    int linha=0;
    int coluna=0;
    double valor=0;

    Node(double valor, Node *proxDireita, Node *proxAbaixo, int l, int c){
        this->valor = valor;
        direita = proxDireita;
        abaixo = proxAbaixo;
        linha = l;
        coluna = c;
    }
};

#endif