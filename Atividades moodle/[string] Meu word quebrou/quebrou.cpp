#include <bits/stdc++.h>
using namespace std;

int main(){
    char frase[100];
    cin.get(frase,100);
    char ordenador = ' ';
    cin >> ordenador;
    
    //Variador;
    int aux = 'a' - 'A';

    //Para maiusculo;
    if(ordenador == 'M'){
        for(int i = 0; frase[i]; i++){
            if(islower(frase[i]) != 0){
                frase[i] -= aux;
            }
            cout << frase[i];
        }   
    }

    //Para minusculo;
    if(ordenador == 'm'){
        for(int i = 0; frase[i]; i++){
            if(isupper(frase[i]) != 0){
                frase[i] += aux;
            }
            cout << frase[i];
        }
    }

    //Inverte case;
    if(ordenador == 'i'){
        for(int i = 0; frase[i]; i++){
            if(isupper(frase[i]) != 0){
                frase[i] += aux;
            }else if(islower(frase[i]) != 0){
                frase[i] -= aux;
            }
        }
        cout << frase;
    }

    //Primeira letra para upper;
    if(ordenador == 'p'){
        frase[0] -= aux;
        for(int i = 1; frase[i]; i++){
            if(isblank(frase[i]) != 0 && isalpha(frase[i+1]) != 0 && isblank(frase[i+2]) == 0){
                if(isupper(frase[i+1]) != 0){
                    i++;
                }else{
                frase[i+1] -= aux;
                }
            }
        }
        cout << frase;
    }
}