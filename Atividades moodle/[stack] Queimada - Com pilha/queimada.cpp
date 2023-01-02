#include <iostream>
#include <stack>
using namespace std;

int main() {
	int lin, col, inilin, inicol;
	lin = col = inilin = inicol = 0;
	cin >> lin >> col >> inilin >> inicol;
	char floresta[lin][col];
	for(int i = 0; i < lin; i++){
	    for(int k = 0; k < col; k++){
	        cin >> floresta[i][k];
	    }
	}
	stack<int> pil; //stack de int pois guardarei as posicoes que devem ser queimadas;
	int aux1 = inilin;
	int aux2 = inicol;
	pil.push(aux1);
	pil.push(aux2);
	
	while(!pil.empty()){
        aux2 = pil.top(); //coluna
	    pil.pop();
	    aux1 = pil.top(); //lin
	    pil.pop();
	    
	    if(aux1 >= lin || aux2 >= col || aux1 < 0 || aux2 < 0){
            //overflow ou underflow;
	    }else if(floresta[aux1][aux2] != '#'){
	        //nao ha o que queimar;
        }else{
            
	        floresta[aux1][aux2] = 'o';
	        
    	    pil.push(aux1-1);
            pil.push(aux2);
            
            pil.push(aux1+1);
            pil.push(aux2);
            
            pil.push(aux1);
            pil.push(aux2+1);
            
            pil.push(aux1);
            pil.push(aux2-1);
        }
 
	}
	
	for(int i = 0; i < lin; i++){
	    for(int k = 0; k < col; k++){
	        cout << floresta[i][k];
	    }
	    cout << endl;
	}
}