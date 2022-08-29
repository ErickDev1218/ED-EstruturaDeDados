#include <bits/stdc++.h>
using namespace std;

int ehPrimo(int a){
    if(a <= 1){
        return 0;
    }

    for(int i = 2; i < a; i++){
        if(a%i == 0){
            return 0;
        }
    }

    return 1;
}



int main(){
    int a = 0, b =0;
    cin >> a >> b;
    int num = 0;
    for(int i = a; a <= b; a++){
        num = ehPrimo(a);
        if(num == 1){
            cout << a << endl;
        }
    }
}