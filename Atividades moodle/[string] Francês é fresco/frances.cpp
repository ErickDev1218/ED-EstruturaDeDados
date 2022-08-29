#include <bits/stdc++.h>
using namespace std;
int main(){
    char frase[100];
    cin.get(frase,100);
    
    for(int i = 0; frase[i]; i++){
        if(frase[i] == ' ' && frase[i-1] == frase[i+1]){
            i++;
        }else{
            cout << frase[i];
        }
    }
    
        
}