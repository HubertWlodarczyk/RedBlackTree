#include <iostream>
#include "RedBlackTree.h"
int main() {
    RedBlackTree* A = new RedBlackTree();
    for(int i=10;i<21;i++) A->Add(i);
    for(int i=1;i<10;i++) A->Add(i);
    A->Show();
    return 0;
}
