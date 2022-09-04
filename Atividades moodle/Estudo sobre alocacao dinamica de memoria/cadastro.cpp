#include <iostream>
using namespace std;
struct people{
    char nome[50];
    int id;
};

people lePeople(){
    people nova;
   
    cin.ignore();
    cout << "Digite o nome a ser cadastrado: ";
    cin.get(nova.nome, 50);
    cout << "Agora, digite o ID do cadastro: ";
    cin >> nova.id;

   
    return nova;
}

people* cadastrar(people *v, int *n, people novaPessoa){
    *n+=1;
   
    people *retorna;
    retorna = new people[*n];
   
    if(v != 0){
        for(int i = 0; i < *n; i++){
            retorna[i] = v[i];
        }
        retorna[*n-1] = novaPessoa;
    }else{
        retorna[0] = novaPessoa;
    }
   
    delete[] v;
    v = nullptr;
   
    return retorna;
}

people *remove(people *v, int *n, int id){
    for(int i = 0; i < *n; i++){
        if(v[i].id == id){
            v[i] = v[*n-1];
            *n-=1;
            cout << endl << "Usuario removido com sucesso!" << endl << endl;
            return v;
        }
    }
    cout << endl << "Usuario nao encontrado!" << endl << endl;
    return v;
}

void achaID(people *v, int *n, int id){
    for(int i = 0; i < *n; i++){
        if(v[i].id == id){
            cout << endl << "O usuario com esse ID eh: " << v[i].nome << endl << endl;
            return;
        }
    }
    cout << endl << "Usuario nao encontrado!" << endl << endl;
}

void fim(people *v, int *c){
    *c = 4;
    delete[] v;
    v = nullptr;
    cout << endl << "Encerrando. Ate mais!" << endl << "================================" << endl;
}



int main(){
    int c = 0;
    people *v = 0;
    int n = 0;
    cout << "Ola, este eh meu codigo de estudo para alocacao dinamica de memoria!"
            << endl << "Vamos comecar!" << endl << "=================================" << endl << endl;
           
           
   
    do{
        cout << "Digite :" << endl << "1 -> para cadastrar um novo usuario."<< endl
        << "2 -> para remover um usuario" <<
        endl << "3 -> para checar os atuais cadastros";
        cout << endl << "4 -> para procurar alguem ja cadastrado";
        cout << endl << "5 -> para encerrar o programa." << endl
        << "=================================" << endl;
       
        cin >> c;
       
        if(c == 1){//Adicionar usuario/
            people a = lePeople();
            v = cadastrar(v,&n,a);
            cout << endl << "Cadastrado com sucesso!" << endl << endl;;
           
        }else if(c == 2){//Remover usuario;
            cout << "Digite o ID do usuario que sera removido: ";
            int proc = 0;
            cin >> proc;
            v = remove(v,&n,proc);
           
           
        }else if(c == 3){//Mostrando vetor;
            cout << endl << "Estas sao as pessoas cadastradas : " << endl;
            for(int i = 0; i < n; i++){
                cout <<"Nome: " << v[i].nome << " - ID: " << v[i].id <<endl;
            }
            cout << endl;
           
        }else if(c == 4){//Procurando alguém
            cout << endl << "Digite um ID para encontrarmos uma pessoa ja cadastrada: ";
            int x = 0;
            cin >> x;
            achaID(v,&n,x);
        }
        else if(c == 5){//Encerrando;
            fim(v,&c);
            return 0;
        }
    }while(c != 5);
}