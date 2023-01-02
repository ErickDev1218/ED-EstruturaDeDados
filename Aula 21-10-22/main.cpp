#include <iostream>
#include "List.h"

using namespace std;

int main(){
    List<float> lista;

    for(int i = 1; i <= 9;i++)
        lista.push_back(i);

    for(int i = 0; i < lista.size(); i ++){// O(n²)
        cout << lista[i] << " ";
    }

    cout << endl;

    for(auto it = lista.begin(); it != lista.end(); ++it){ //O(n)
        cout << *it << " ";
    }
    cout << endl;

    for(auto e : lista){
        cout << e << " ";
    }
    cout << endl;
}