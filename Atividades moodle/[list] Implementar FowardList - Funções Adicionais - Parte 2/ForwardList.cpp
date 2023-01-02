/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include <stdexcept>
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
 * Funcoes adicionais - Parte 2
 ***********************************************************/

// Concatena a lista atual com a lista lst.
// A lista lst eh modificada apos essa operacao.
// Por exemplo, seja l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8] e l2 = [ ]
// Restricao: estar proibido usar funcoes auxiliares para resolver esta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::concat(ForwardList& lst) {
    if(m_head->next == nullptr && lst.m_head->next != nullptr){//Caso a L1 esteja vazia e a L2 não;
        m_head = lst.m_head->next;
        lst.m_head = nullptr;
    }else{//Caso a L1 nao esteja vazia;
        Node* aux = m_head; //Estou no sentila;
        m_size += lst.m_size;
        lst.m_size = 0;
        while(aux->next != nullptr){
            aux = aux->next;
        }//Cheguei no ultimo nó;
        aux->next = lst.m_head->next;
        lst.m_head = nullptr;
    }
}

// Remove da lista todas as ocorrencias do Item val.
// Se a lista estiver vazia, esta funcao nao faz nada.
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados 
void ForwardList::remove(const Item& val) {
    while(true){
        Node *aux1 = m_head->next; //Estou no primeiro elemento pós sentinela;
        if(aux1->value == val){//Caso o primeiro da lista ja deva ser removido
            m_head = aux1->next;
            delete aux1;
            m_size--;

        }else{
            while(aux1->next->value != val){//Caminhando até chegar antes de quem deve sair;
                aux1 = aux1->next;
            }
            Node *del = aux1->next;
            aux1->next = del->next;
            delete del;
            m_size--;
        }
        if(aux1->next == nullptr){
            break;
        }
    }
}
// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
ForwardList* ForwardList::clone(){
    ForwardList *retorna = new ForwardList; // Cabeça+sentinela da nova lista
    Node*aux = m_head; //Estou no sentinela da lista "velha";
    Node*aux2 = retorna->m_head;//Estou no sentinela da nova lista;
    while(aux->next != nullptr){
        aux = aux->next;
        Node *novo = new Node(aux->value,nullptr);
        aux2->next = novo;
        aux2 = aux2->next;
    }
    retorna->m_size = m_size;
    return retorna;
}

// Copia os elementos do vector vec para o final da lista.
// Esta funcao deve ter complexidade O(n) no pior caso
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node*aux = m_head; //Estou no sentinela;
    while(aux->next != nullptr){
        aux = aux->next;
    }//Cheguei no ultimo elemento;
    for(int i = 0; i < vec.size(); i++){
        Node *novo = new Node(vec[i],nullptr);
        aux->next = novo;
        aux = aux->next;
        m_size++;
    }
}
// Troca o conteudo dessa lista pelo conteudo de lst. 
// Os tamanhos das listas podem diferir.
// Apos a chamada para esta funcao, os elementos nesta lista
// sao aqueles que estavam em lst antes da chamada, 
// e os elementos de lst sao aqueles que estavam nesta lista.
void ForwardList::swap(ForwardList& lst) {
    Node *aux = m_head; // Estou no sentinela;
    m_head->next = lst.m_head->next;
    lst.m_head->next = aux->next;
}

// Determina se a lista lst, passada por parametro, eh igual
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
// e o valor do k-esimo elemento da primeira lista eh igual ao
// k-esimo valor da segunda lista.
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
bool ForwardList::equals(const ForwardList& lst) const {
    Node *aux1 = m_head; // Estou no sentinela
    Node *aux2 = lst.m_head;// Estou no sentinela

    int cont1 = 0;
    int cont2 = 0;

    while(aux1->next != nullptr){
        aux1 = aux1->next;
        cont1++;
    }

    while(aux2->next != nullptr){
        aux2 = aux2->next;
        cont2++;
    }
    if(cont1 == cont2){
        int cont = 0;
        aux1 = m_head;
        aux2 = lst.m_head;
        while(aux1->next != nullptr){
            aux1 = aux1->next;
            aux2 = aux2->next;
            if(aux1->value == aux2->value){
                cont++;
            }
        }
        if(cont == cont1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}
// Inverte a ordem dos nos (o primeiro node passa a ser o ultimo, 
// o segundo passa a ser o penultimo, etc.)
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um numero constante deles),
// mas nao pode alocar novos nos.
// Repetindo: estar proibido chamar o operador new nesta questao.
// Restricao: Tambem nao eh permitido usar funções auxiliares nesta questao
void ForwardList::reverse() {
    if(m_head->next == nullptr){//Caso a lista nao tenha nenhum elemento;
        return;
    }else{
        Node* ini = m_head; //Estou no sentinela;
        Node* prox = nullptr;
        Node* ant = nullptr;

        while(ini != nullptr){
            prox = ini->next;
            ini->next = ant;
            ant = ini;
            ini = prox;
        }
        ini = ant;
    }
}
// retorna o elemento na posicao 'index'
// Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
// mensagem de erro "index out of range". Caso contrario retorne o elemento.
// Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
Item& ForwardList::get(int index) {
    if(index < 0 || index >= m_size){
        throw std::range_error("index out of range");
    }else{
        Node *aux = m_head;
        for(int i = 0; i < index+1;i++){
            aux = aux->next;
        }
        return aux->value;
    }
}

const Item& ForwardList::get(int index) const {
    if(index < 0 || index >= m_size){
        throw std::range_error("index out of range");
    }else{
        Node * aux = m_head;
        for(int i = 0; i < index+1; i++){
            aux = aux->next;
        }
        return aux->value;
    }
}
