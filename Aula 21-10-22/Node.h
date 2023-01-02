#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
struct Node{
    public:
    T value;
    Node *prev; // Nó anterior
    Node *next; //Proximo nó
    

    Node(const T& val, Node *prev, Node *next){
        value = val;
        this->prev = prev;
        this->next = next;
    }
    ~Node(){
        std::cout << "Node " << value << " liberado.\n";
    }

};




#endif