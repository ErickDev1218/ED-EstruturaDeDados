#include <bits/stdc++.h>
using namespace std;

struct aluno {
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

aluno cadastro(){
    
    aluno novato;
    
    getline(cin,novato.nome);
    cin >> novato.matricula;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    getline(cin,novato.disciplina);
    cin >> novato.nota;
    
    return novato;
}

void test(aluno novato){
    if(novato.nota >= 7.0){
        cout << novato.nome << " aprovado(a) em " << novato.disciplina << endl;
    }else{
        cout << novato.nome << " reprovado(a) em " << novato.disciplina << endl;
    }
}


int main(){
    aluno novato = cadastro();
    test(novato);
}
