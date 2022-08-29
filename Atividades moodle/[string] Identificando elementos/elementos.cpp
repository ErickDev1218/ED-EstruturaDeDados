#include <bits/stdc++.h>
using namespace std;

int main(){
    char frase[100];
    cin.get(frase,100);

    for(int i = 0; frase[i]; i++){
        //Testando espaços;
        if(isspace(frase[i])){
            i++;
        }
        
        if(frase[i] >= 'a' || frase[i] <= 'z'){
            cout << "str ";
        }
    }
}