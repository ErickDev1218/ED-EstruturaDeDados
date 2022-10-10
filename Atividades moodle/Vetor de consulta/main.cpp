#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

vector <int> matchingStrings(vector <string> queries, vector <string> search){
    vector <int> final;
    int cont = 0;
    for(int i = 0; i < search.size(); i++){
        for(int k = 0; k < queries.size(); k++){
            if(queries[k] == search[i]){
                cont++;
            }
        }
        final.push_back(cont);
        cont = 0;
    }
    return final;
}

int main(){
    vector <string> search; //Vetor de buscas
    vector <string> queries; //Vetor de consultas

    int searchLenght = 0;// Tamanho do vetor de buscas
    int queriesLenght = 0; // Tamanho do vetor de consultas

    cin >> queriesLenght; //Lendo o tamanho do vetor de consultas;
    cin.ignore();

    string queriesInit;
    getline(cin,queriesInit); // Lendo o vetor de consultas;
    stringstream queriesSS;
    queriesSS << queriesInit;
    string aux;
    while(queriesSS >> aux){
        queries.push_back(aux); //Passando os elementos para o vetor de consultas;
    }
    
    
    cin >> searchLenght; //Lendo o tamanho do vetor de busca;
    cin.ignore();
    string searchInit;
    getline(cin,searchInit);// Lendo o vetor de busca;
    stringstream searchSS;
    searchSS << searchInit;
    string aux1;
    while(searchSS >> aux1){
        search.push_back(aux1);// Passando os elementos para o vetor de busca;
    }

    vector <int> imp = matchingStrings(queries,search);

    for(int i = 0; i < imp.size();i++){
        if(i+1 < imp.size()){
            cout << imp[i] << " ";
        }else{
            cout << imp[i];
        }
    }
    cout << endl;

}