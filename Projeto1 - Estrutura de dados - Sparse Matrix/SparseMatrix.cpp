/******************************************************************************************************
 * TRABALHO IMPLEMENTADO EM DUPLA POR:
 * ANTONIO ERICK FREITAS FERREIRA
 * JOAO PEDRO SOARES MATIAS
*******************************************************************************************************/
#include "SparseMatrix.h"
#include <iostream>
using namespace std;

//Construtor.
SparseMatrix::SparseMatrix(int m, int n){ //m linhas e n colunas.
    if(m > 0 && n > 0){
        
        quantLinhas = m;
        quantColunas = n;

        head = new Node(0,nullptr,nullptr,0,0);
        head->direita = head;
        head->abaixo = head;
        for(int i = 0; i < m; i++){//Criando sentinelas de linhas.
            Node *andador = head;
            while(andador->abaixo != head){
                andador = andador->abaixo;
            }
            
            Node *novoSentinela = new Node(0,nullptr,nullptr,i+1,0);

            novoSentinela->direita = novoSentinela;
            novoSentinela->abaixo = head;
            andador->abaixo = novoSentinela;
        }
       

        for(int i = 0; i < n; i++){//Criando sentinelas das colunas.
            Node *andador = head;
            while(andador->direita != head){
                andador = andador->direita;
            }

            Node *novoSentinela = new Node(0,nullptr,nullptr,0,i+1);
            novoSentinela->direita = head;
            novoSentinela->abaixo = novoSentinela;
            andador->direita = novoSentinela;
        }
    }else{
        throw range_error("Error! Valores invalidos para uma matriz!");
    }
}

int SparseMatrix::getquantLinhas(){
    return quantLinhas;
}
int SparseMatrix::getquantColunas(){
    return quantColunas;
}

/*Esta funcao-membro faz o valor na celula (i, j) da matriz ser igual a value, onde i
é a linha e j é a coluna. Se ja houver um valor nessa posicao, ele e atualizado para
esse novo valor. Essa funcao deve checar se os ındices i, j passados por parametro
sao validos; se nao forem validos, uma excecao deve ser lancada.*/

void SparseMatrix::insert(int i, int j, double value){
    //Primeiro, verifico se a linha e a coluna buscada existe de fato nessa matriz.
    if(i > quantLinhas || j > quantColunas || i < 1 || j < 1){
        throw range_error("ERROR!");
    }
    //Agora preciso saber se esse cara esta na matriz
    if(get(i,j) != 0 && value != 0){
        Node *caminha = head;
        while(caminha->linha != i){
            caminha = caminha->abaixo;
        }
        while(caminha->coluna != j){
            caminha = caminha->direita;
        }
        if(caminha->linha == i && caminha->coluna == j){
            caminha->valor = value;
        }
    }else if(get(i,j) != 0 && value == 0){
        //Movimentação pela linha.
        Node*fixLin = head;
        Node*searchLin = nullptr;
        Node*prevLin = nullptr;

        while(fixLin->linha != i){
            fixLin = fixLin->abaixo;
        }

        //Arrumo os outros 2 ponteiros para também ficarem na linha que eu quero.
        prevLin = fixLin; //A ideia do prev é fazer com que ele ande sempre 1 nó atrás do searchLin.
        searchLin = fixLin->direita;

        while(searchLin->coluna != j && searchLin->direita != fixLin){
            prevLin = searchLin;
            searchLin = searchLin->direita;
        }
        //O que acabei de fazer foi tentar caminhar por essas colunas para saber se essa linha ja existe
        //algum nó. Caso tenha algum nó, o searchLin irá apontar para ele o prevLin apontará para um nó antes.
        //Caso não exista nenhum nó, searchLin e prevLin apontarão para o fixLin.
        

        //Replico a mesma lógica só que para as colunas.
        //Movimentação pela coluna.
        Node*fixCol = head;
        Node*searchCol = nullptr;
        Node*prevCol = nullptr;

        while(fixCol->coluna != j){
            fixCol = fixCol->direita;
        }
        prevCol = fixCol;
        searchCol = fixCol->abaixo;

        while(searchCol->linha != i && searchCol->abaixo != fixCol){
            searchCol = searchCol->abaixo;
        }
        if(searchLin->linha == i && searchCol->coluna == j){
            prevCol->abaixo = searchCol->abaixo;
            prevLin->direita = searchLin->direita;
            delete searchLin;
        }
    }else{
        //Movimentação pela linha.
        Node*fixLin = head;
        Node*searchLin = nullptr;
        Node*prevLin = nullptr;

        while(fixLin->linha != i){
            fixLin = fixLin->abaixo;
        }

        //Arrumo os outros 2 ponteiros para também ficarem na linha que eu quero.
        prevLin = fixLin; //A ideia do prev é fazer com que ele ande sempre 1 nó atrás do searchLin.
        searchLin = fixLin->direita;

        while(searchLin->coluna != j && searchLin->direita != fixLin){
            prevLin = searchLin;
            searchLin = searchLin->direita;
        }
        //O que acabei de fazer foi tentar caminhar por essas colunas para saber se essa linha ja existe
        //algum nó. Caso tenha algum nó, o searchLin irá apontar para ele o prevLin apontará para um nó antes.
        //Caso não exista nenhum nó, searchLin e prevLin apontarão para o fixLin.
        

        //Replico a mesma lógica só que para as colunas.
        //Movimentação pela coluna.
        Node*fixCol = head;
        Node*searchCol = nullptr;
        Node*prevCol = nullptr;

        while(fixCol->coluna != j){
            fixCol = fixCol->direita;
        }
        prevCol = fixCol;
        searchCol = fixCol->abaixo;

        while(searchCol->linha != i && searchCol->abaixo != fixCol){
            searchCol = searchCol->abaixo;
        }
        //Caso exista algum nó por essa coluna, searchCol irá aponta-lo e prevCol ficará um nó antes dele.
        //Caso não exista, ambos ficarão apontando para fixCol.

        //Nesse momento eu já posso criar esse novo nó, o que me resta é arrumar seus ponteiros.
        Node *novo = new Node(value,nullptr,nullptr,i,j);

        //Caso não tenha ninguem nessa linha e na coluna;
        if(fixLin->direita == fixLin && fixCol->abaixo == fixCol){
            novo->direita = fixLin;
            novo->abaixo = fixCol;

            fixLin->direita = novo;
            fixCol->abaixo = novo;
        }

        //Caso tenha alguém na linha mas não na coluna;
        else if(fixLin->direita != fixLin && fixCol->abaixo == fixCol){
            //Agora preciso saber se esse novo nó será inserido em um lugar na linha
            //antes ou depois desse nó que já existe.
            if(searchLin->coluna < j){//Caso meu ultimo cara seja menor de onde eu quero inserir.
                novo->direita = searchLin->direita;
                novo->abaixo = fixCol;

                searchLin->direita = novo;
                fixCol->abaixo = novo;
            }else if(j == 1){ //Caso eu queira inserir na primeira coluna.
                novo->direita = fixLin->direita;
                novo->abaixo = fixCol;
                fixLin->direita = novo;
                fixCol->abaixo = novo;
            }
        }
        //Caso eu tenha um nó na coluna mas não na linha.
        else if(fixLin->direita == fixLin && fixCol->abaixo != fixCol){
            //Agora eu preciso saber se eu quero inserir num lugar
            //depois ou antes desse nó que ja existe.
            if(searchCol->linha < i){ //Caso eu precise adicionar em um lugar depois
                novo->abaixo = searchCol->abaixo;
                novo->direita = fixLin;
                searchCol->abaixo = novo;
                fixLin->direita = novo;
            }else if(i == 1){ // Caso precise adicionar na primeira linha;
                novo->abaixo = fixCol->abaixo;
                novo->direita = fixLin;
                fixCol->abaixo = novo;
                fixLin->direita = novo;
            }
        }
        //Caso eu já tenha alguem na linha e na coluna.
        else if(fixLin->direita != fixLin && fixCol->abaixo != fixCol){
            //Agora preciso saber se irei inserir num local após um nó existente na linha
            //ou na coluna
            if(i==j && searchLin->coluna > i && searchCol->linha > j){
                novo->abaixo = prevCol->abaixo;
                novo->direita = prevLin->direita;
                prevCol->abaixo = novo;
                prevLin->direita = novo;
            }else if(searchLin->coluna < j && searchCol->linha < i){
                novo->abaixo = searchCol->abaixo;
                novo->direita = searchLin->direita;
                searchCol->abaixo = novo;
                searchLin->direita = novo;
            }else if(searchLin->coluna < j && i == 1){
                novo->abaixo = fixCol->abaixo;
                novo->direita = searchLin->direita;
                fixCol->abaixo = novo;
                searchLin->direita = novo;
            }else if((searchCol->linha < i || prevCol->linha < i) && j == 1){
                novo->abaixo = searchCol->abaixo;
                novo->direita = fixLin->direita;
                searchCol->abaixo = novo;
                fixLin->direita = novo;
            }else if(searchCol->linha > i && searchLin->direita == fixLin){
                novo->abaixo = prevCol->abaixo;
                novo->direita = searchLin->direita;
                prevCol->abaixo = novo;
                searchLin->direita = novo;
            }else if(searchLin->coluna > j && searchCol->abaixo == fixCol){
                novo->direita = prevLin->direita;
                novo->abaixo = searchCol->abaixo;
                prevLin->direita = novo;
                searchCol->abaixo = novo;

            }
        }
    }
}




double SparseMatrix::get(int i, int j){
    if((i > quantLinhas || j > quantColunas) || (i == 0 && j == 0)){
        throw range_error("ERROR!");
    }else{
        Node*search = head;
        while(search->linha != i && search->abaixo != head){
            search = search->abaixo;
        }
        Node*fix = search;
        while(search->coluna != j && search->direita != fix){
            search = search->direita;
        }

        if(search->linha == i && search->coluna == j){
            return search->valor;
        }else{
            return 0;
        }
    }
}

SparseMatrix::~SparseMatrix(){
    Node*auxLin = head;
    while(auxLin->abaixo != head){
        auxLin = auxLin->abaixo;
        Node*prevLin = nullptr;
        Node*ProxLin = auxLin->direita;

        while(ProxLin->direita != auxLin){
            prevLin = ProxLin;
            ProxLin = ProxLin->direita;
            delete prevLin;
        }
    }
    
    auxLin = head->abaixo;
    while(auxLin->abaixo != head){
        Node*prev = auxLin;
        auxLin = auxLin->abaixo;
        delete prev;
    }

    Node*auxCol = head->direita;
    while(auxCol->direita != head){
        Node*prev = auxCol;
        auxCol = auxCol->direita;
        delete prev;
    }
    delete head;
    cout << "Matriz Liberada!" << endl;
}

void SparseMatrix::print(){
    Node*auxLin = head->abaixo;
    Node*anda = nullptr;
    //O que eu nao consigo entender nesse for é o fato dele nao me permitir usar i & k = 0,
    // e depois usar no if i+1 ou k+1;
    for(int i = 1; i <= quantLinhas; i++){
        anda = auxLin->direita;
        for(int k = 1; k <= quantColunas; k++){
            if(anda->linha == i && anda->coluna == k){
                cout << anda->valor << " ";
                anda = anda->direita;
            }else{
                cout << "0 ";
            }

            if(auxLin->direita->linha == 0 || auxLin->direita->linha == i){
                auxLin = auxLin->abaixo;
            }
        }
        cout << endl;
    }
}