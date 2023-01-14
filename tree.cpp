#include"tree.h"
#include<list>

using namespace std;

template<typename E>
E& Position<E>::operator*() {
    return elem;
}

template<typename E>
Position<E> Position<E>::parent() const {
    return *parentPos;
}

template<typename E>
list<Position<E> > Position<E>::children() const {
    return childrenPos;
}

template<typename E>
bool Position<E>::isRoot() const {
    return parentPos == NULL;
}

template<typename E>
bool Position<E>::isExternal() const {
    return childrenPos.empty();
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

template class Position<int>;
template class Tree<int>;