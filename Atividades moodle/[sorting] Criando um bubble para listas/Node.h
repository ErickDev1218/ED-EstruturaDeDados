// NAO MEXA NESTE ARQUIVO. ELE JA ESTA FINALIZADO.
#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int value;  // valor
    Node *prev; // ponteiro para o node anterior
    Node *next; // ponteiro para o proximo node

    Node(const int &val, Node *prev, Node *next) {
        value = val;
        this->prev = prev;
        this->next = next;
    }
};

#endif