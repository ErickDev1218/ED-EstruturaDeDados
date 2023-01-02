// Lista duplamente encadeada circular com node sentinela
#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List {
private:
    Node *m_head {nullptr}; // ponteiro para o node sentinela
    int m_size {0}; // numero de elementos na lista atualmente

public:
    // Construtor default: cria uma lista vazia, ou sejaaa, 
    // com o ponteiro m_head apontando para o node sentinela
    List() { // O(1)
        m_head = new Node(0, nullptr, nullptr);
        m_head->prev = m_head->next = m_head;
    }

    // insere um elemento no final da lista
    void push_back(const int& val) { // O(1)
        Node *aux = new Node(val, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }

    // retorna o numero de elementos na lista
    int size() const { // O(1)
        return m_size;
    }

    // retorna true se e somente se lista eh vazia
    bool empty() const { // O(1)
        return m_size == 0;
    }

    // deixa a lista vazia novamente, liberando memoria
    void clear() { // O(n)
        Node *aux = m_head->prev;
        while(aux != m_head) {
            Node *temp = aux;
            aux = aux->prev;
            delete temp;
        }
        m_head->prev = m_head->next = m_head;
        m_size = 0;
    }

    // Destrutor
    ~List() { // O(n)
        clear();
        delete m_head;
    }

    // iterador para a lista
    class iterator {
    private:
        Node *pointer {nullptr};
    public:
        iterator(Node *ptr) {
            pointer = ptr;
        }
        iterator& operator++() {
            pointer = pointer->next;
            return *this;
        }
        bool operator!=(const iterator& it) {
            return this->pointer != it.pointer;
        }
        int& operator*() {
            return pointer->value;
        }
    };

    // retorna um iterador para o primeiro elemento da lista
    iterator begin() {
        return iterator(m_head->next);
    }

    // retorna um iterador para uma posicao apos o ultimo elemento
    iterator end() {
        return iterator(m_head);
    }

    /**
     * Funcao que ordena os elementos da lista em ordem crescente.
     * Esta funcao ordena a lista usando o algoritmo bubblesort.
     * Para implementar esta funcao, voce deve satisfazer as 
     * seguintes restricoes:
     * 1 - Nao eh permitido usar arrays ou outras estruturas de
     *     dados auxiliares, inclusive, nao eh permitido instanciar
     *     nodes adicionais. Voce pode declarar variaveis ponteiro
     *     auxiliares para te ajudar.
     * 2 - Seu algoritmo deve ter complexidade de pior caso O(n^2), 
     *     assim como a versao original dele para vetores.
     * O objetivo aqui eh pegar o algoritmo bubblesort que vimos em sala
     * e implementar uma versao equivalente dele para listas. Nao eh 
     * obrigatorio usar dois loops for, se voce quiser usar loop while ou 
     * do-while, voce pode usar. O que voce nao pode fazer eh escrever 
     * um algoritmo que nao seja o bubblesort.
     * Voce pode implementar tanto o bubblesort melhorado quanto o bubblesort
     * nao-melhorado: fica ao seu criterio.
     */
    void bubblesort() {
        // Fazer
        // Node*camFirst = m_head->next; //ponteiro começando do inicio;
        // Node*camEnd = m_head->prev; //ponteiro iniciando do final;
        // while(camFirst->next != m_head){//Andando até o final.
        //     while(camEnd != camFirst){
        //         if(camEnd->value < camEnd->prev->value){ //testando o swap;
        //             int aux = camEnd->value;
        //             camEnd->value = camEnd->prev->value; 
        //             camEnd->prev->value = aux;
        //         }
        //         camEnd = camEnd->prev;
        //     }
        //     camFirst = camFirst->next;
            
        // }
        for(Node*camFirst = m_head->next; camFirst != m_head; camFirst = camFirst->next){
            for(Node*camEnd = m_head->prev; camEnd != camFirst; camEnd = camEnd->prev){
                if(camEnd->value < camEnd->prev->value){
                    int aux = camEnd->value;
                    camEnd->value = camEnd->prev->value;
                    camEnd->prev->value = aux;
                }
            }
            
        }
        
        
    }
};

#endif