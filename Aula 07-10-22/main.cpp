#include <iostream>
#include "FowardList.h"
using namespace std;

int main(){
    FowardList lst;

    for(int i = 0; i <= 9; i ++)
        lst.push_back(i);

    cout << lst.toString() << endl;
}