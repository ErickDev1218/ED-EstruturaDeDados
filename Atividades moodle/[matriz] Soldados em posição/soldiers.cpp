#include <bits/stdc++.h>
using namespace std;

int main(){
    int m[3][3];
    
    for(int i = 0; i < 3;i++){
        for(int k = 0; k < 3; k++){
            cin >> m[i][k];
        }
    }
    
    int contador = 0;
    int menor = 0;
    
    for(int i = 0; i < 3; i++){
        menor = 0;
        for(int k = 1; k < 3; k++){
            menor = m[k][i];
            if(m[k-1][i] > m[k][i]){
                contador++;
            }
        }
    }
    
    cout << contador << endl;
}