#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    if(nrot == 0){
        return;
    }else{
        for(int i = 0; i < nrot; i++){
            int aux = vet[vet.size()-1];
            for(int k = vet.size()-1; k > 0; k--){
                vet[k] = vet[k-1];
            }
            vet[0] = aux;
        }
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

