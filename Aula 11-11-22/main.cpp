#include <iostream>
#include <sstream>
#include "Stack.h"
#include <string>
using namespace std;

string reverse(string line){
    Stack<char> *pilha = new Stack<char>();
    string res = "";
    
    for(int i = 0; i <= line.size(); i++){
        if(line[i] != ' ' && line[i] != '\0'){
            pilha->push(line[i]);
        }else{
            while(!pilha->empty()){
                res+= pilha->top();
                pilha->pop();
            }
            res+= " ";
        }
        
        
        
        // pilha->push(line[i]);
        // if(line[i] == ' ' || line[i+1] == '\0'){
        //     while(!pilha->empty()){
        //         res += pilha->top();
        //         pilha->pop();
        //     }
        //     res += " ";
        // }
    }

    // for(int i = 0; i < line.size(); i++){
    //     res += pilha->top();
    //     pilha->pop();
    // }
    
    return res;

}

int main(){

    string line;
    getline(cin,line);
    cout << reverse(line);




    // Stack<int> *pilha = new Stack<int>();
    
    // for(int i = 55; i <= 62; i++)
    //     pilha->push(i);

    // while(!pilha->empty()){
    //     cout << pilha->top() << endl;
    //     pilha->pop();
    // }
    // delete pilha;

    
}