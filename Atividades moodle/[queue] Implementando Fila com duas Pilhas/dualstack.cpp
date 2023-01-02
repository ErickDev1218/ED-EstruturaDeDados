#include <stack>
#include <iostream>
using namespace std;
//questao muito mal explicada.
int main(){
    stack<int> pilha1; //deposito
    stack<int> pilha2; //pratileira
    
    int rep = 0;
    cin >> rep;
    for(int i = 0; i < rep; i++){
        int comand = 0;
        cin >> comand;
        if(comand == 1){
            int insert = 0;
            cin >> insert;
            pilha1.push(insert);
        }
        else if(comand == 2){
            pilha2.pop();
        }
        else if(comand == 3){
            cout << pilha2.top() << endl;
        }
        
        
        if(pilha2.empty()){
            while(!pilha1.empty()){
                pilha2.push(pilha1.top());
                pilha1.pop();
            }
        }
        
    } 
}