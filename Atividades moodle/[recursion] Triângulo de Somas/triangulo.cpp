#include <iostream>
using namespace std;

int imprimeVetor(int v[],int n){
    if(n < 1){
        return v[0];
    }else{
        int novo[n-1];
        for(int i = 0; i < n-1; i++){
            novo[i] = v[i] + v[i+1];
        }
        imprimeVetor(novo,n-1);

        cout << "[";
        for(int i = 0; i < n; i++){
            if(i+1 < n){
                cout << v[i] << " ";
            }else{
                cout << v[i];
            }
        }
        cout << "]" << endl;
    }
}



int main(){
    int tam;
    cin >> tam;

    int v[tam];
    for(int i = 0; i < tam; i++){
        cin >> v[i];
    }

    imprimeVetor(v,tam);
}