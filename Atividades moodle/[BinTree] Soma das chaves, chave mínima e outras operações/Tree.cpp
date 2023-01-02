#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include "Tree.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};


Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Tree::~Tree() {
    _clear(_root);
}

Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}


int Tree::sum_keys() { // TODO
    return _sum_keys(_root);
}

int Tree::_sum_keys(Node *node) { // TODO
    if(node == nullptr){
        return 0;
    }
    int sum = 0;
    sum += node->key;
    sum += _sum_keys(node->left) + _sum_keys(node->right);
    return sum;
    
}

// Para fazer essa funcao, suponha que as arvores dos testes nunca serao vazias,
// assim, sempre havera um menor valor de chave a ser retornado
int Tree::min_key() { // TODO
    return _min_key(_root);
}


// Supoe que o ponteiro recebido sempre eh diferente de nullptr
//ARRUMAR ESSA FUNCAO DEPOIS
int Tree::_min_key(Node *node) { // TODO
    int value = node->key;
    int comp1 = 1000;
    int comp2 = 1000;
    if(node->left != nullptr){
        comp1 = _min_key(node->left);
    }
    if(node->right != nullptr){
        comp2 = _min_key(node->right);
    }
    if(comp1 > comp2 && value > comp2){
        return comp2;
    }else if(comp2 > comp1 && value > comp1){
        return comp1;
    }else{
        return value;
    }
    
    
}

int Tree::total_internal_nodes() { // TODO
    _total_internal_nodes(_root);
}
    
int Tree::_total_internal_nodes(Node *node) { // TODO
    int count = 0;
    if(node == nullptr){ //Caso de parada
        return 0;
    }else{
        if(node->left != nullptr || node->right != nullptr){
            count++;
            count +=  _total_internal_nodes(node->left);
            count +=  _total_internal_nodes(node->right);
        }
        return count;
    }
}

int Tree::um_filho() { // TODO
    _um_filho(_root);
}

int Tree::_um_filho(Node *node) { // TODO
    if(node == nullptr){ //Caso de parada.
        return 0;
    }else{
        int count = 0;
        count += _um_filho(node->left);
        count += _um_filho(node->right);
        
        if((node->left != nullptr && node->right == nullptr) || (node->right != nullptr && node->left == nullptr)){
            count++;
        }
        return count;
    }
}