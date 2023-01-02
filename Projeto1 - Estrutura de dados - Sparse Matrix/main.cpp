/******************************************************************************************************
 * TRABALHO IMPLEMENTADO EM DUPLA POR:
 * ANTONIO ERICK FREITAS FERREIRA
 * JOAO PEDRO SOARES MATIAS
*******************************************************************************************************/
#include "SparseMatrix.h"
#include <iostream>
#include <fstream>
using namespace std;
SparseMatrix* arquivo(string file){
        fstream arquivo;
        arquivo.open(file,fstream::in);

        if(arquivo.is_open()){
        int quantLin;
        int quantCol;

        arquivo >> quantLin;
        arquivo >> quantCol;
        SparseMatrix *temp = new SparseMatrix(quantLin,quantCol);

        int lin;
        int col;
        double valor;
        for(int i = 0; i < quantLin; i++){
            for(int k = 0; k < quantCol; k++){
                arquivo >> lin;
                arquivo >> col;
                arquivo >> valor;
                temp->insert(lin,col,valor);
            }
        }
        return temp;
    }else{
        cout << "ERROR!" << endl;
        return nullptr;
    }
}


SparseMatrix*sum(SparseMatrix *first, SparseMatrix *second){
    if(first->getquantLinhas() != second->getquantLinhas()){
        //throw range_error("ERROR! Impossivel fazer essa conta!");
        cout << "ERROR! Impossivel fazer essa soma!" << endl;
        return nullptr;
    }else{
        SparseMatrix *novo = new SparseMatrix(first->getquantLinhas(),first->getquantColunas());
        for(int i = 0; i < first->getquantLinhas(); i++){
            for(int j = 0; j < first->getquantColunas(); j++){
                novo->insert(i+1,j+1,first->get(i+1,j+1)+second->get(i+1,j+1));
            }
        }

        return novo;
    }
}

SparseMatrix* multiply(SparseMatrix *first, SparseMatrix* second){
    if(first->getquantColunas() != second->getquantLinhas()){
        cout << "ERROR! Impossivel fazer essa multiplicacao!" << endl;
        return nullptr;
    }else{
        SparseMatrix* novo = new SparseMatrix(first->getquantLinhas(),second->getquantColunas());
        double inserir = 0;
        for(int i = 0; i < first->getquantLinhas(); i++){
            for(int j = 0; j < second->getquantColunas(); j++){
                for(int k = 0; k < first->getquantLinhas(); k++){
                    inserir += (first->get(i+1,k+1) * second->get(k+1,j+1)) + novo->get(i+1,j+1);
                }
                novo->insert(i+1,j+1,inserir);
                inserir = 0;
            }
        }
        return novo;
    }
}

int main(){
    cout << endl;
    cout << "Ola. Neste arquivo estou realizando casos de teste desse codigo em questao. Compile o codigo no seu computador e leia com atencao o terminal!" << endl << "==============================================================================================================================================" << endl << endl;
    cout << "Esta matriz foi criada percorrendo linha a linha" << endl;
    SparseMatrix *x = new SparseMatrix(5,5);
    for(int i = 1; i <= 5; i++){
        for(int k = 1; k <= 5; k++){
            x->insert(i,k,k);
        }
    }
    x->print();
    cout << endl;
    
    cout << "Esta matriz foi criada em X" << endl;
    SparseMatrix *y = new SparseMatrix(5,5);
    y->insert(1,1,5);
    y->insert(2,2,5);
    y->insert(3,3,5);
    y->insert(4,4,5);
    y->insert(5,5,5);
    y->insert(5,1,5);
    y->insert(4,2,5);
    y->insert(2,4,5);
    y->insert(1,5,5);
    
    y->print();
    cout << endl;

    cout << "Esta matriz foi criada em um formato de losangulo." << endl;
    SparseMatrix *losa = new SparseMatrix(5,5);
    losa->insert(3,1,99);
    losa->insert(2,2,99);
    losa->insert(4,2,99);
    losa->insert(1,3,99);
    losa->insert(5,3,99);
    losa->insert(2,4,99);
    losa->insert(4,4,99);
    losa->insert(3,5,99);
    
    losa->print();
    cout << endl;

    cout << "Esta matriz foi criado coluna por coluna" << endl;
    SparseMatrix *z = new SparseMatrix(3,3);
    z->insert(1,1,1);
    z->insert(2,1,2);
    z->insert(3,1,3);

    z->insert(1,2,4);
    z->insert(2,2,5);
    z->insert(3,2,6);

    z->insert(1,3,7);
    z->insert(2,3,8);
    z->insert(3,3,9);

    z->print();
    cout << endl;

    cout << "Esta matriz foi criada linha a linha saltando elementos" << endl;
    SparseMatrix *i = new SparseMatrix(4,4);
    i->insert(1,1,99);
    i->insert(1,3,99);
    i->insert(2,2,99);
    i->insert(2,4,99);
    i->insert(3,1,99);
    i->insert(3,3,99);
    i->insert(4,2,99);
    i->insert(4,4,99);

    i->print();
    cout << endl;

    cout << "Esta matriz foi criada coluna a coluna saltando elementos" << endl;
    SparseMatrix *k = new SparseMatrix(4,4);
    k->insert(1,1,1);
    k->insert(3,1,1);
    k->insert(2,2,1);
    k->insert(4,2,1);
    k->insert(1,3,1);
    k->insert(3,3,1);
    k->insert(2,4,1);
    k->insert(4,4,1);

    k->print();
    cout << endl;

    cout << "Agora irei criar uma matriz generica qualquer e irei remover indice a indice" << endl;

    SparseMatrix *j = new SparseMatrix(6,3);
    for(int i = 1; i <= j->getquantLinhas(); i++){
        for(int k = 1; k <= j->getquantColunas(); k++){
            j->insert(i,k,i+1);
        }

    }
    j->print();
    cout << endl << "Agora irei desalocar elemento por elemento" << endl;
    for(int i = 1; i <= j->getquantLinhas(); i++){
        for(int k = 1; k <= j->getquantColunas(); k++){
            j->insert(i,k,0);
        }
    }
    j->print();
    cout << endl;

    cout << "A proxima matriz tera os elementos em X e desalocarei tambem em X" << endl;
    cout << "Esta matriz foi criada em X" << endl;
    SparseMatrix *l = new SparseMatrix(5,5);
    l->insert(1,1,7);
    l->insert(2,2,7);
    l->insert(3,3,7);
    l->insert(4,4,7);
    l->insert(5,5,7);
    l->insert(5,1,7);
    l->insert(4,2,7);
    l->insert(2,4,7);
    l->insert(1,5,7);
    
    l->print();
    cout << endl << "Agora vou desalocar exatamente o item do meio" << endl;
    l->insert(3,3,0);
    l->print();
    cout << endl;

    cout << "Como ja provado, eh possivel alocar ou desalocar elementos com esse codigo. Agora irei testar a funcao que le um arquivo e cria a matriz." << endl << "Primeira matriz com arquivo: " << endl;

    SparseMatrix *file = arquivo("MatrizTest.txt");
    SparseMatrix *file2 = arquivo("MatrizTest2.txt");
    file->print();
    cout << endl << "Segunda matriz com arquivo: " << endl;
    file2->print();

    cout << endl << "Agora irei testar a soma e multiplicacao entre matrizes usando matrizes que ja existem." << endl;
    cout << "Matriz A: " << endl;
    x->print();
    cout << endl << "Matriz B: " << endl;
    y->print();

    cout << endl << "A soma entre as duas matrizes: " << endl;
    SparseMatrix *soma = sum(x,y);
    soma->print();

    cout << endl << "A multiplicacao entre as duas matrizes: " << endl;
    SparseMatrix *mult = multiply(x,y);
    mult->print();
    cout << endl << "Deletando todas as matrizes!" << endl;


    delete x;
    delete y;
    delete losa;
    delete z;
    delete i;
    delete k;
    delete j;
    delete l;
    delete file;
    delete file2;
    delete soma;
    delete mult;

    cout << endl << "Bom, daqui para baixo deixo em aberto ao possuidor desse codigo o direito de altera-lo (apenas a main) para criar seus proprios casos de teste, se assim quiser." << endl << "Por: Antonio Erick Freitas Ferreira & Joao Pedro Soares Matias." << endl << endl;

}