// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n){
    lin = m;
    col = n;
    mat = new int *[lin];
    for(int i = 0; i < lin; i++){
        mat[i] = new int[col]{0};
    }
}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
    for(int i = 0; i < lin; i++){
        delete[] mat[i];
    }
    cout << "matriz liberada" << endl;
}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
    int x = 0;
    for(int i = 0; i < lin; i++){
        x++;
    }
    return x;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
    int x = 0;
    for(int i = 0; i < col; i++){
        x++;
    }
    return x;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
    return mat[i][j];
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
    mat[i][j] = valor;
}

// Imprimir a matriz 
void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << endl;
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {
    Matriz *aux = new Matriz(lin,col);

    if(B.lin != this->lin){
        cout << "nao foi possivel somar" << endl;
        return nullptr;
    }else{

        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                aux->mat[i][j] = this->mat[i][j] + B.mat[i][j];
            }
        }
        return aux;
    }
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B) {
    Matriz *aux = new Matriz(lin,B.col);
    int ajuda = 0;

    if(B.lin != this->col){
        cout << "nao foi possivel multiplicar" << endl;
        return nullptr;
    }else{
        for(int i = 0; i < this->lin; i++){
            for(int j = 0; j < B.col; j++){
                for(int x = 0; x < B.lin; x++) {
                    ajuda +=  mat[i][x] * B.mat[x][j];
                }

            aux->mat[i][j] = ajuda;
            ajuda = 0;
        }
    }
        return aux;
    }

}