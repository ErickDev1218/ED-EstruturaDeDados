#ifndef NODE_H
#define NODE_H

class Node{
    friend class FowardList;

    private:
        int value;
        Node* next;
    public:
        Node(const int& value, Node* ptrNext){
            this->value = value;
            this->next = ptrNext;
        }
        
};



#endif