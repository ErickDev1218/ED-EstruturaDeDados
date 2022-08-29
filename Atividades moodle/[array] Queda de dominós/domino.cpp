#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,aux = 0;
    cin >> x;

    const int tam = x;
    int vet[tam];

    for(int i = 0; i < tam; i++){
        cin >> vet[i];
    }

    for(int i = 1; i < tam; i++){
        if(vet[i] >= vet[i-1]){
            aux++;
        }
    }

    if(aux == x-1){
        cout << "ok";
    }else{
        cout << "precisa de ajuste!";
    }
    
}