#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if(m_head == nullptr){//Caso lista vazia
        Node *aux = new Node(val,m_head);
        m_head = aux;
        m_head->next = m_head;
        m_size++;
    }else{//Caso lista ja com elementos
        Node *aux = m_head;
        while(aux->next != m_head){
            aux = aux->next;
        }
        Node *novo = new Node(val,m_head);
        aux->next = novo;
        m_size++;
    }

}

void CircularList::pop_back() {
    if(m_head == nullptr){//Lista vazia
        return;
    }
    if(m_head->next == m_head){//Lista com 1 elemento
        delete m_head;
        m_head = nullptr;
        m_size--;
    }else{//Lista com dois ou mais elementos
        Node *aux = m_head;
        while(aux->next->next != m_head){ //Proximo do proximo;
            aux = aux->next;
        }
        delete aux->next;
        aux->next = m_head;
        m_size--;
    }
}

std::string CircularList::toString() const {
    std::stringstream ss;
    ss << "[ ";
    if(m_head != nullptr){
        ss << m_head->value << " ";
        Node *aux = m_head;
        while(aux->next != m_head){
            aux = aux->next;
            ss << aux->value << " ";
        }
    }
    ss << "]";
    return ss.str();
}

Item& CircularList::operator[](int index) {
    Node *aux = m_head;
    for(int i = 0; i < index; i++){
        aux = aux->next;
    }
    return aux->value;
    
}

const Item& CircularList::operator[](int index) const {
    Node *aux = m_head;
    for(int i = 0; i < index; i++){
        aux = aux->next;
    }
    return aux->value;
}

void CircularList::clear() {
    if(m_head != nullptr){
        Node* aux1 = m_head;
        Node*aux2 = m_head->next;
        while(aux1 != m_head){
            aux2 = aux2->next;
            delete aux1;
            aux1 = aux2;
        }
        delete m_head;
        m_head = nullptr;
        m_size = 0;
    }
}

CircularList::~CircularList() {
    clear();
}

void clearRecursivo(Node *nodeAtual, Node *head){
    if(nodeAtual->next == head){
        delete nodeAtual;
    }else{
        clearRecursivo(nodeAtual->next,head);
        delete nodeAtual;
    }
}

void CircularList::clear_recursivo(){
    clearRecursivo(m_head,m_head);
}

void CircularList::insert(int index, const Item& value){
    if(index < 0 || index > m_size){
        throw std::range_error("Fail: index invalido!");
    }
    Node *aux = m_head;
    for(int i = 0; i < index-1; i++){
        aux = aux->next;
    }
    Node *novo = new Node(value,aux->next);
    aux->next = novo;
    m_size++;
}
