#include <bits/stdc++.h>
using namespace std;

int main(){
    int m[3][3];
    int num = 0;
    int aux = 0;
    
    
    for(int i = 0;i < 3;i++){
        for(int k = 0;k < 3; k++){
            cin >> m[i][k];
        }
    }
    
    aux += m[0][0] + m[0][1] + m[0][2];
    
    for(int i = 0; i < 3; i++){
        num = 0;
        for(int k = 0; k < 3; k++){
            num += m[i][k];
            }
        }
        if(num != aux){
            cout << "nao" << endl;
            return 0;        
    }
    
    cout << "sim" << endl;
}