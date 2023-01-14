#include<iostream>
#include<list>
#include"tree.h"

using namespace std;

int main() {    
    Position<string> *position0 = new Position<string>;
    *(*position0) = "Electronics R\' US";
    cout << *(*position0) << endl;

    Tree<string>* tree0 = new Tree<string>(*(position0));

    Position<string> *position10 = new Position<string>;
    *(*position10) = "R&D";
    position10->setParent(position0);
    position0->addChild(*position10);
    tree0->addPosition(*position10);

    Position<string> *position11 = new Position<string>;
    *(*position11) = "Sales";
    position11->setParent(position0);
    position0->addChild(*position11);
    tree0->addPosition(*position11);

    Position<string> *position12 = new Position<string>;
    *(*position12) = "Purchasing";
    position12->setParent(position0);
    position0->addChild(*position12);
    tree0->addPosition(*position12);

    Position<string> *position13 = new Position<string>;
    *(*position13) = "Manufacturing";
    position13->setParent(position0);
    position0->addChild(*position13);
    tree0->addPosition(*position13);

    // list<Position<string> > children = position0->children();
    list<Position<string> > children = tree0->positions();

    for (Position<string> child : children) {
        cout << *child << endl;
    }


    return 0;
}