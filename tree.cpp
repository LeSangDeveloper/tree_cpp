#include"tree.h"
#include<list>

using namespace std;

template<typename E>
E& Tree<E>::Position<E>::operator*() {
    return v->elem;
}

template<typename E>
Tree<E>::Position Tree<E>::Position<E>::parent() const {
    return v->parent;
}

template<typename E>
Tree<E>::PositionList Tree<E>::Position<E>::children() const {
    return v->children;
}

template<typename E>
bool Tree<E>::Position<E>::isRoot() {
    return v->parent == NULL;
}

template<typename E>
bool Tree<E>::Position<E>::isExternal() {
    return v->children == NULL;
}

template<typename E> 
int Tree<E>::size() {
    return 1;
}

template<typename E> 
bool Tree<E>::empty() {
    return true;
}

template<typename E> 
Position Tree<E>::root() {
    return root;
}

template<typename E> 
PositionList Tree<E>::positions() {
    return positions;
}