#include <bits/stdc++.h>
using namespace std;

int ehVogal(char a){
    if(a == 'a' || a == 'e' ||  a == 'i' ||  a == 'o' ||  a == 'u' || a == 'A' || a == 'E' ||  a == 'I' ||  a == 'O' ||  a == 'U'){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    string receptora;
    getline(cin,receptora);
    
    stringstream frase;
    frase << receptora;
    
    string a;
    
    string nova;
    
    while(frase >> a){
        if(ehVogal(a[0]) == 1 && ehVogal(a[1]) == 0 && ehVogal(a[2]) == 1){ //testando se eh vogal seguida de consoante;
            for(int i = 0; i < 2; i++){
                // cout << a[0];
                // cout << a[1];
                nova += a[0];
                nova += a[1];
            }
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
        }else if(ehVogal(a[0]) == 1 && ehVogal(a[1]) == 0 && ehVogal(a[2]) == 0){ //testando se eh vogal seguida de consoante e consoante
            for(int i = 0; i < 2; i++){
                //cout << a[0];
                nova += a[0];
            }
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
        }else if(ehVogal(a[0]) == 0 && ehVogal(a[1]) == 1 && ehVogal(a[2]) == 1 && a.size() > 3){//testando se eh consoante seguida de vogal vogal e > 3
            for(int i = 0; i < 2; i++){
                // cout << a[0];
                // cout << a[1];
                // cout << a[2];
                nova += a[0];
                nova += a[1];
                nova += a[2];
            }
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
            
        }else if(ehVogal(a[0]) == 0 && ehVogal(a[1]) == 0 && ehVogal(a[2]) == 1 && ehVogal(a[3]) == 0){//testando se eh consoante consoante vogal consoante
            for(int i = 0; i < 2; i++){
                // cout << a[0];
                // cout << a[1];
                // cout << a[2];
                nova += a[0];
                nova += a[1];
                nova += a[2];
            }
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
        }
        else if(ehVogal(a[0]) == 0 && ehVogal(a[1]) == 1 && a.size() > 3){ //testando se eh consoante seguida de vogal e > 3
            for(int i = 0; i < 2; i++){
                // cout << a[0];
                // cout << a[1];
                nova += a[0];
                nova += a[1];
            }
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
        }
        else{
            //cout << a << ' ';
            nova+= a;
            nova+= ' ';
        }
        
    }
    
    if(nova[nova.size()-1] == ' '){
        for(int i = 0; i < (nova.size()-1); i++){
            cout << nova[i];
        }
    }else{
        cout << nova;
    }
}