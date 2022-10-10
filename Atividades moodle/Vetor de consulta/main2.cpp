#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector <string> x {"ola","mundo"};

    vector <string> y {"mundo", "oi"};

    vector <int> final;
    int cont = 0;
    for(int i = 0; i < x.size(); i++){
        cont = 0;
        for(int k = 0; k < y.size(); k++){
            if(x[i] == y[k]){
                cont++;
            }
        }
        final.push_back(cont);
    }

    for(int i = 0; i < final.size(); i++)
        cout << final[i] << " ";


}