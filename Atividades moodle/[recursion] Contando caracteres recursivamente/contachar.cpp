#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    
    if(n >= 1){
        if(str[n-1] == c){
            return 1+contaCaracteres(str,n-1,c);
        }else{
            return contaCaracteres(str,n-1,c);
        }
    }
    
    
    // fazer
}

int main() 
{
    string frase;
    char search;
    getline(cin,frase);
    //cin.ignore();
    cin >> search;
    int n = frase.size();

    int a = contaCaracteres(frase,n,search);
    cout << a;
   // fazer
}