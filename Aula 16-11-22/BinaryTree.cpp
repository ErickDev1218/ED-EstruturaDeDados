#include <iostream>
#include <sstream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    root = nullptr;
}
//Percuso de preordem para criação de arvore com ss.
Node* serializeTree(stringstream& ss){
    string valor;
    ss >> valor;
    if(valor == "#"){ //caso de parada
        return nullptr;
    }else{
        int key = stoi(valor); //stoi = string to int
        Node* aux = new Node(key,nullptr,nullptr);
        aux->left = serializeTree(ss);
        aux->right = serializeTree(ss);
        return aux;
    }
}
BinaryTree::BinaryTree(string serial){
    stringstream ss{serial};
    root = serializeTree(ss);
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 * 
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    root = new Node(value,lchild.root,rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    return root != nullptr && root->left == nullptr && root->right == nullptr;
}
/**
 * @brief 
 * 
 * @param node 
 * @return true 
 * @return false 
 */
bool contains_recursivo(Node *node, int value){
    if(node == nullptr){
        return false;
    }else if(node->key == value){
        return true;
    }else{
        return contains_recursivo(node->left,value) || contains_recursivo(node->right,value);
    }
}

/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    return contains_recursivo(root,value);
}

/**
 * @brief Print the keys saved on the tree
 */
//Funcao recursiva que imprime todas as chaves da
//arvore enraizada no ponteiro node
void print_keys_recursiva(Node *node){
    if(node == nullptr){ //caso de parada
        return;
    }else{
        cout << node->key << " ";
        print_keys_recursiva(node->left);
        print_keys_recursiva(node->right);
    }

    /*
        print sem recursão em preordem

        stack<Node*>pilha;
        pilha.push(root);

        while(!pilha.empty()){
            Node *aux = pilha.top();
            pilha.pop();
            if(aux != nullptr){
                cout << aux->key;
                pilha.push(aux->right);
                pilha.push(aux->left);
            }
        }
    */
}

void BinaryTree::print_keys() const {
    print_keys_recursiva(root);
}

/**
 * @brief empties the tree
 */
//Limpa uma arvore a partir da raiz e retorna um ponteiro para uma arvore vazia
Node* clear_recursivo(Node* node){
    /*
    if(node == nullptr){ //caso de parada
        return nullptr;
    }else{
        clear_recursivo(node->left);
        clear_recursivo(node->right);
        delete node;
        return nullptr;
    }
    */
    if(node!= nullptr){
        clear_recursivo(node->left);
        clear_recursivo(node->right);
        delete node;
    }
    return nullptr;
    
}
void BinaryTree::clear() {
    root = clear_recursivo(root);
}

BinaryTree::~BinaryTree() {
    clear();
}
void serialization_rec(Node *node, stringstream& oss){
    if(node == nullptr){
        oss << "# ";
    }else{
        oss << node->key << " ";
        serialization_rec(node->left,oss);
        serialization_rec(node->right,oss);

    }
}

std::string BinaryTree::serialization() const{
    stringstream ss;
    serialization_rec(root,ss);
    return ss.str();
}

