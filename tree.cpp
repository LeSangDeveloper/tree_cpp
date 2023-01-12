#include"tree.h"
#include<list>

using namespace std;

template<typename E>
E& Position<E>::operator*() {
    return v->elem;
}

template<typename E>
Position<E> Position<E>::parent() const {
    return v->parent;
}

template<typename E>
list<Position<E> > Position<E>::children() const {
    return v->children;
}

template<typename E>
bool Position<E>::isRoot() const {
    return v->parent == NULL;
}

template<typename E>
bool Position<E>::isExternal() const {
    return v->children == NULL;
}

template<typename E> 
int Tree<E>::size() const {
    return 1;
}

template<typename E> 
bool Tree<E>::empty() const {
    return true;
}

template<typename E> 
Position<E> Tree<E>::root() const {
    return rootNode;
}

template<typename E> 
list<Position<E> > Tree<E>::positions() const {
    return positionNodes;
}