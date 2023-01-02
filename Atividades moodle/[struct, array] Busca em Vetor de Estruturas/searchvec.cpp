#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct registra{
    int matricula;
    string nome;
    float media;
};

registra matriculando(){
    registra novo;
    
    cin >> novo.matricula;
    cin.ignore();
    
    getline(cin,novo.nome);
    
    cin >> novo.media;
    
    return novo;
}
    

int main(){
    int quantAlunos;
    cin >> quantAlunos;
    
    registra matriculados[quantAlunos];
    
    for(int i = 0; i < quantAlunos; i++){
        matriculados[i] = matriculando(); 
    }
    
    int search;
    cin >> search;
    
    for(int i = 0; i < quantAlunos; i++){
        if(matriculados[i].matricula == search){
            cout << matriculados[i].nome << endl << fixed << setprecision(1) << matriculados[i].media << endl;
            return 0;
        }
    }
    
    cout << "NAO ENCONTRADA" << endl;
    

}