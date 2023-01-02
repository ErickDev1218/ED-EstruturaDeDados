#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    /*
    BinaryTree tnull;
    BinaryTree t34(34, tnull, tnull);
    BinaryTree t21(21, tnull, tnull);
    BinaryTree t76(76, t34, t21);
    BinaryTree t55(55, tnull, tnull);
    BinaryTree t1(1, t76, t55);

    cout << t1.contains(34) << endl;

    //t1.print_keys();
    cout << endl;
    //t1.clear();
    //t1.print_keys();
    cout << t1.serialization() << endl;
    */

   BinaryTree tree("3 4 5 # # 6 # # 7 # 8 9 # # 10 # #");
   tree.print_keys();
   cout << endl << tree.serialization() << endl;

}