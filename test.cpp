#include<iostream>
#include<list>
#include"tree.h"

using namespace std;

template<typename E>
int depth(Position<E> position) {
    if (position.isRoot())
        return 0;
    return 1 + depth(position.parent());
}

template<typename E>
int height1(const Tree<E>& T) {
    int h = 0;
    list<Position<E> > nodes = T.positions();
    for (typename list<Position<E> >::iterator p = nodes.begin(); p != nodes.end(); ++p) {
        if (p->isExternal()) {
            int temp = depth(*(p));
            h = temp > h ? temp : h; 
        }
    }
    return h;
}

template<typename E>
int height2(const Position<E>& p) {
    if (p.isExternal()) return 0;
    int h = 0;
    list<Position<E> > nodes = p.children();
    for (typename list<Position<E> >::iterator q = nodes.begin(); q != nodes.end(); ++q) {
        int temp = height2(*q);
        h = temp > h ? temp : h;
    }
    return  1 + h;
}

template<typename E>
void preOrderPrint(const Position<E>& p) {
    cout << *p;
    if (!p.isExternal()) {
        list<Position<E> > children = p.children();
        cout << "( ";
        for (typename list<Position<E> >::iterator q = children.begin(); q != children.end(); ++q) {
            if (q != children.begin()) cout << " ";
            preOrderPrint(*q);
        } 
        cout << " )";
    }
}

template<typename E>
void postOrderPrint(const Position<E>& p) {
    list<Position<E> > children = p.children();
    for (typename list<Position<E> >::iterator q = children.begin(); q != children.end(); ++q) {
        postOrderPrint(*q);
        cout << " ";
    }
    cout << *p;
}

int main() {    
    Position<string> *position0 = new Position<string>;
    *(*position0) = "Electronics R\' US";
    cout << *(*position0) << endl;

    Tree<string>* tree0 = new Tree<string>(*(position0));

    // R&D
    Position<string> *position10 = new Position<string>;
    *(*position10) = "R&D";
    position10->setParent(position0);
    position0->addChild(*position10);
    tree0->addPosition(*position10);

    // Sales
    Position<string> *position11 = new Position<string>;
    *(*position11) = "Sales";
    //// Sales -> Domestic
    Position<string> *position20 = new Position<string>;
    *(*position20) = "Domestic";
    position20->setParent(position11);
    position11->addChild(*position20);
    tree0->addPosition(*position20);
    //// Sales -> International
    Position<string> *position21 = new Position<string>;
    *(*position21) = "International";
    //// Sales -> International -> Canada
    Position<string> *position30 = new Position<string>;
    *(*position30) = "Canada";
    position30->setParent(position21);
    position21->addChild(*position30);
    tree0->addPosition(*position30);
    //// Sales -> International -> S. America
    Position<string> *position31 = new Position<string>;
    *(*position31) = "S. America";
    position31->setParent(position21);
    position21->addChild(*position31);
    tree0->addPosition(*position31);
    //// Sales -> International -> Overseas
    Position<string> *position32 = new Position<string>;
    *(*position32) = "Overseas";
    //// Sales -> International -> Overseas -> Africa
    Position<string> *position40 = new Position<string>;
    *(*position40) = "Africa";
    position40->setParent(position32);
    position32->addChild(*position40);
    tree0->addPosition(*position40);
    //// Sales -> International -> Overseas -> Europe
    Position<string> *position41 = new Position<string>;
    *(*position41) = "Europe";
    position41->setParent(position32);
    position32->addChild(*position41);
    tree0->addPosition(*position41);
    //// Sales -> International -> Overseas -> Asia
    Position<string> *position42 = new Position<string>;
    *(*position42) = "Asia";
    position42->setParent(position32);
    position32->addChild(*position42);
    tree0->addPosition(*position42);
    //// Sales -> International -> Overseas -> Australia
    Position<string> *position43 = new Position<string>;
    *(*position43) = "Australia";
    position43->setParent(position32);
    position32->addChild(*position43);
    tree0->addPosition(*position43);

    position32->setParent(position21);
    position21->addChild(*position32);
    tree0->addPosition(*position32);

    position21->setParent(position11);
    position11->addChild(*position21);
    tree0->addPosition(*position21);

    position11->setParent(position0);
    position0->addChild(*position11);
    tree0->addPosition(*position11);

    // Purchasing
    Position<string> *position12 = new Position<string>;
    *(*position12) = "Purchasing";
    position12->setParent(position0);
    position0->addChild(*position12);
    tree0->addPosition(*position12);

    // Manufacturing
    Position<string> *position13 = new Position<string>;
    *(*position13) = "Manufacturing";
    //// Manufacturing -> CD
    Position<string> *position22 = new Position<string>;
    *(*position22) = "CD";
    position22->setParent(position13);
    position13->addChild(*position22);
    tree0->addPosition(*position22);
    //// Manufacturing -> TV
    Position<string> *position23 = new Position<string>;
    *(*position23) = "TV";
    position23->setParent(position13);
    position13->addChild(*position23);
    tree0->addPosition(*position23);
    //// Manufacturing -> CD
    Position<string> *position24 = new Position<string>;
    *(*position24) = "Tuner";
    position24->setParent(position13);
    position13->addChild(*position24);
    tree0->addPosition(*position24);

    position13->setParent(position0);
    position0->addChild(*position13);
    tree0->addPosition(*position13);
    tree0->setRoot(position0);

    list<Position<string> > nodes = tree0->positions();

    Position<string> root = tree0->root();
    preOrderPrint(root);
    cout << endl;
    postOrderPrint(root);
    cout << endl;
    cout << "height of tree: " << height2(root) << endl; 

    return 0;
}