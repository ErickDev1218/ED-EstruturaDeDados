#include <iostream>
#include <vector>
using namespace std;

int main(){
    int quantFil = 0; // Tamanho da fila;
    cin >> quantFil;

    vector <int> fila;
    for(int i = 0; i < quantFil; i++){
        int temp = 0;
        cin >> temp;
        fila.push_back(temp); // Criando a fila;
    }

    int quantSai = 0; //Quantidade de pessoas que saem;
    vector <int> saiFila;
    for(int i = 0; i < quantFil; i++){
        int temp = 0;
        cin >> temp;
        saiFila.push_back(temp); // Criando a fila de saida;
    }

    for(int i = 0; i < saiFila.size(); i++){
        for(int k = 0; k < fila.size();k++){
            if(fila[k] == saiFila[i]){
                fila.erase(fila.begin()+k);
            }
        }
    }

    for(int i = 0; i < fila.size();i++){
        if(i+1 < fila.size()){
            cout << fila[i] << " ";
        }else{
            cout << fila[i];
        }
    }
}