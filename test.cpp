#include<iostream>
#include<list>
#include"tree.h"

using namespace std;

int main() {    
    Position<int> position1;
    *position1 = 1;
    cout << position1.isRoot();
    cout << *position1;


    return 0;
}