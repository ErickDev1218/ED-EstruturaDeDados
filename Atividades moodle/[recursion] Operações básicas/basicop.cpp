#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int menorvet(vector <int> v, int x){ // Função que acha e imprime o menor valor do vetor!
    if(x == 1){
        return v[x-1];
    }else{
        int aux = menorvet(v,x-1);
        
        if(v[x-1] > aux){
            return aux;
        }else{
            return v[x-1];
        }
    }
}


int somavet(vector <int> v, int x){ // Função que soma os valores do vetor!
    if(x == 1){
        return v[x-1];
    }else{
        return somavet(v,x-1) + v[x-1]; 
    }
    
}

int multiplicavet(vector <int> v, int x){ // Função que multiplica os valores do vetor!
    if(x == 1){
        return v[x-1];
    }else{
        return multiplicavet(v,x-1) * v[x-1];
    }
}

void print(vector <int> v, int x){ // Função que printa o vetor!
    if(x == 1){
        cout << v[x-1] << " ";
    }else{
        print(v,x-1);
        cout << v[x-1] << " ";
    }
}

void invertevet(vector <int> v, int x, int aux){ //Função que inverte o vetor!
    if(aux > x){
        int aux2 = v[x];
        v[x] = v[aux - 1];
        v[aux - 1] = aux2;
        invertevet(v, x+1, aux-1);
    }
}

void contrariovet(vector <int> v, int x){ //Função que imprime o vetor ao contrario!
    if(x == 1){
        cout << v[x-1] << " ";
    }else{
        cout << v[x-1] << " ";
        contrariovet(v, x-1);
    }
}





int main(){
    vector <int> v;
    
    string frase;
    getline(cin,frase);
    
    stringstream receptora;
    receptora << frase;
    
    int x;
    
    while(receptora >> x){
        v.push_back(x);
    }
    
    //Lembrar que posso acessar cada indice como um vetor comum (Ex: v[i]).
    
    //Imprimindo o vetor
    cout << "vet : [ ";
    print(v,v.size());
    cout << "]" << endl;
    
    //Imprimindo o vetor ao contrario
    cout << "rvet: [ ";
    contrariovet(v,v.size());
    cout << "]" << endl;
    
    //Imprimindo a soma do vetor
    cout << "sum : " << somavet(v,v.size()) << endl;
    
    //Imprimindo a multiplicacao do vetor
    cout << "mult: " << multiplicavet(v,v.size()) << endl;
    
    //Imprimindo o menor valor do vetor
    cout << "min : " << menorvet(v,v.size()) << endl;
    
    //Imprimindo o vetor ao contrario
    cout << "inv : [ ";
    contrariovet(v,v.size());
    cout << "]" << endl;
    
}