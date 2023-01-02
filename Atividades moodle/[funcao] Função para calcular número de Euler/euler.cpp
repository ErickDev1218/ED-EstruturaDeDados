#include <bits/stdc++.h>
using namespace std;


double fatorial(double x){
    double fat = 1;
    while(x > 1){
        fat *= x--;
    }
    return fat;
}

double euler(double n){
    double euler = 2;
    while(n > 1){
        euler += (1/fatorial(n));
        n--;
    }
    return euler;
}

int main(){
    double num = 0;
    cin >> num;
    cout << fixed << setprecision(6) << euler(num);
}