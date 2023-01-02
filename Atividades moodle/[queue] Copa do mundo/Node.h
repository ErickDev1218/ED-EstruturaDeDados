#ifndef NODE_H
#define NODE_H

template <typename T> 
struct Node {

    T id;
    Node *next;

    Node(const T& ident, Node*nxt){
        this->id = ident;
        this->next = nxt;
    }
    
    ~Node(){
        delete next;
    }
};

#endif