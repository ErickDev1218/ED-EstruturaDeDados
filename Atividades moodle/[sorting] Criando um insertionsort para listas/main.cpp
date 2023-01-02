// NAO MEXA NESTE ARQUIVO. ELE JA ESTA FINALIZADO.
#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List list; // cria lista vazia

    // ler os elementos da entrada. Para parar a leitura, digite
    // CTRL+D (no linux) ou CTRL+Z (no windows)
    int value;
    while(cin >> value) 
        list.push_back(value);

    // imprime a lista original na tela 
    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;

    list.insertionsort(); // ordena a lista

    // imprime a lista ordenada
    for(auto it = list.begin(); it != list.end(); ++it) 
        cout << *it << " ";
    cout << endl;
}