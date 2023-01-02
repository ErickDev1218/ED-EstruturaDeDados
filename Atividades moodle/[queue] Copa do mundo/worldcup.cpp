#include "queue.h"
#include <iostream>
using namespace std;
int main(){
    Queue<char> *oitavas = new Queue<char>();
    Queue<char> *quartas = new Queue<char>();
    Queue<char> *semifin = new Queue<char>();
    Queue<char> *final = new Queue<char>();
    
    for(int i = 0; i < 16; i++){
        oitavas->push('A'+i);
    }
    int mm = 0,nn = 0;
    char comp1, comp2;
    
    for(int k = 0; k < 8; k++){
        mm = nn = 0;
        cin >> mm >> nn;
        comp1 = oitavas->first();
        oitavas->pop();
        comp2 = oitavas->first();
        oitavas->pop();
        //cout << comp1 << " " << comp2 << endl;
        if(mm > nn){
            quartas->push(comp1);
        }else{
            quartas->push(comp2);
        }
    }
    //quartas.show();
    delete oitavas;
    
    for(int i = 0; i < 4; i++){
        mm = nn = 0;
        cin >> mm >> nn;
        comp1 = quartas->first();
        quartas->pop();
        comp2 = quartas->first();
        quartas->pop();
        //cout << comp1 << " " << comp2 << endl;
        if(mm > nn){
            semifin->push(comp1);
        }else{
            semifin->push(comp2);
        }
    }
    delete quartas;
    for(int i = 0; i < 2; i++){
        mm = nn = 0;
        cin >> mm >> nn;
        comp1 = semifin->first();
        semifin->pop();
        comp2 = semifin->first();
        semifin->pop();
        if(mm > nn){
            final->push(comp1);
        }else{
            final->push(comp2);
        }
        
        
    }
    delete semifin;
    
    mm = nn = 0;
    cin >> mm >> nn;
    comp1 = final->first();
    final->pop();
    comp2 = final->first();
    final->pop();
    if(mm > nn){
        cout << comp1 << endl;
    }else{
        cout << comp2 << endl;
    }
    delete final;
}