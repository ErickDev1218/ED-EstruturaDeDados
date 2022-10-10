#ifndef FOWARDLIST_H
#define FOWARDLIST_H
#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>

class FowardList{
    private:
        Node* m_head{nullptr};
        int m_size{0};

    public:
        FowardList(){ //Construtor default: cria uma lista vazia internamente, m_head aponta para o sentinela.
            m_head = new Node(0, nullptr); //SENTINELA!!
            m_size = 0;
        }
        //Insere val no inicio da lista
        void push_front(int val){
            m_head->next = new Node(val,m_head->next);
            m_size++;
        }
        //Insere val no final da lista
        void push_back(int val){
            Node *aux = m_head;
            while(aux->next != nullptr){
                aux = aux->next;
            }
            Node *novo = new Node(val,nullptr);
            aux->next = novo;
            m_size++;
        }

        //Retorna uma string contendo os elementos da lista;
        std::string toString(){
            std::stringstream ss;
            Node *atual = m_head->next;
            ss << "[";
            while(atual != nullptr){
                ss << atual->value << " ";
                atual = atual->next;
            }
            ss << "]";
            return ss.str();
        }
        //Deixa a lista vazia novamente com 0 elementos;
        void clear(){
            while(m_head->next != nullptr){
                Node *temp = m_head->next;
                m_head->next = temp->next;
                delete temp;
            }
            m_size = 0;
        }
        //Destrutor;
        ~FowardList(){
            clear();
            delete m_head;
        }


};




#endif