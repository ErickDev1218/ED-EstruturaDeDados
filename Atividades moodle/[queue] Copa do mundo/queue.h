#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue{
    private:
        Node<T>*head = nullptr;
        Node<T>*tail = nullptr;
        int m_size = 0;
        
    public:
        Queue() = default;
        ~Queue(){
            delete head;
        }
        bool empty(){
            return m_size == 0;
        }
        int size(){
            return m_size;
        }
        T& first(){
            if(empty()){
                //std::cout << "Aq" << std::endl;
                throw std::underflow_error("Fila vazia!");
            }
            return head->id;
        }
        T& last(){
            if(empty()){
                throw std::underflow_error("Fila vazia!");
            }
            return tail->id;
        }
        void push(const T& val){
            Node<T> *aux = new Node<T>(val,nullptr);
            if(m_size == 0){
                tail = aux; 
                head = aux;
            }else{
                tail->next = aux;
                tail = aux;
            }
            m_size++;
        }
        void pop(){
            if(!empty()){
                Node<T> *aux = head->next;
                head->next = nullptr; //por conta do destrutor;
                delete head;
                head = aux;
                m_size--;
                if(m_size == 0){
                    tail = nullptr;
                }
            }
        }
        
        void show(){
            Node<T>*aux = head;
            while(aux != nullptr){
                std::cout << aux->id << " ";
                aux = aux->next;
            }
        }
        
};

#endif