/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 1
 ***********************************************************/

// retorna uma referencia para o primeiro elemento na lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
Item& ForwardList::front() {
    if(m_head == nullptr){ //Caso só tenha o sentinela!
        throw std::range_error("Fail: Lista vazia!");
    }else{//Caso tenha pelo menos 1 elemento na lista
        return m_head->next->value;
    }
}

const Item& ForwardList::front() const {
    if(m_head->next == nullptr){ //Caso só tenha o sentinela!
        throw std::range_error("Fail: Lista vazia!");
    }else{//Caso tenha pelo menos 1 elemento na lista
        return m_head->next->value;
    }
}
// insere um elemento no inicio da lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::push_front(const Item& val) {
    if(m_head->next == nullptr){//Caso tenha apenas o sentinela;
        Node *novo = new Node(val,nullptr);
        m_head->next = novo;
    }else{//Caso já tenha pelo menos 1 elemento na lista;
        Node *aux = m_head; //Estou no sentinela!
        Node *novo = new Node(val,aux->next);
        aux->next = novo;
    }
    m_size++;
}

// deleta o primeiro elemento da lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::pop_front() {
    if(m_head == nullptr){ //Caso só tenha o sentinela!
        throw std::range_error("Fail: Lista vazia!");
    }else{
        Node *aux = m_head;
        Node *aux2 = aux->next;
        aux = aux2->next;
        delete aux2;
        m_head->next = aux;
        m_size--;
    }
}
// retorna uma referencia para o ultimo elemento na lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
Item& ForwardList::back() {
    Node*aux = m_head->next; //Estou no sentinela;
    while(aux->next != nullptr){//Indo até o ultimo nó
        aux = aux->next;
    }
    return aux->value;
}

const Item& ForwardList::back() const {
    Node*aux = m_head->next; //Estou no sentinela;
    while(aux->next != nullptr){//Indo até o ultimo nó
        aux = aux->next;
    }
    return aux->value;
}
// insere um elemento no final da lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::push_back(const Item& val) {
    Node*aux = m_head; //Estou no sentinela
    while(aux->next != nullptr){
        aux = aux->next;
    }
    //Cheguei no ultimo
    Node*novo = new Node(val,nullptr);
    aux->next = novo;
    m_size++;
    
}

// deleta o ultimo elemento da lista
// Restricao: estar proibido usar funções auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::pop_back() {
    if(m_head->next == nullptr){ //Caso só tenha o sentinela!
        throw std::range_error("Fail: Lista vazia!");
    }else{
        Node*aux = m_head; //Estou no sentinela;
        while(aux->next->next != nullptr){
            aux = aux->next;
        }
        //Cheguei no penultimo;
        Node *deletado = aux->next; //Este está no ultimo;
        delete deletado;
        m_size--;
        aux->next = nullptr;
    }
}