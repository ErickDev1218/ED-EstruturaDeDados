#include <bits/stdc++.h>
using namespace std;

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

aluno cadastrador(){
    aluno a;
    
    cin>>a.nome;
    cin >> a.matricula;
    //cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cin>>a.disciplina;
    cin >> a.nota;
    
    return a;
}

void comparador(aluno novo,aluno novo1){
    if(novo.nota > novo1.nota){
        cout << novo.nome << " , " << fixed << setprecision(1) << novo.nota << endl;
    }else if(novo1.nota > novo.nota){
        cout << novo1.nome << " , " << fixed << setprecision(1) << novo1.nota << endl;
    }else{
        cout << novo.nome << " e " << novo1.nome << " , " << fixed << setprecision(1) << novo.nota << endl;
    }
    
    
    
    
     
  
}



int main(){
    aluno novo = cadastrador();
    aluno novo1 = cadastrador();
    comparador(novo,novo1);
}