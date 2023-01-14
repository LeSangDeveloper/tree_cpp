#include"tree.h"
#include<list>
#include<string>

using namespace std;

template<typename E>
E& Position<E>::operator*() {
    return elem;
}

template<typename E>
void Position<E>::setParent(Position<E>* parent) {
    parentPos = parent;
}

template<typename E>
void Position<E>::addChild(Position<E> child) {
    childrenPos.push_back(child);
}

template<typename E>
Position<E> Position<E>::parent() const {
    return *parentPos;
}

template<typename E>
list<Position<E> > Position<E>::children() const {
    // TODO modify later
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
    if (rootNode == NULL) return 0;
    return 1 + positionNodes.size();
}

template<typename E> 
bool Tree<E>::empty() const {
    return size() == 0;
}

template<typename E> 
Position<E> Tree<E>::root() const {
    return *(rootNode);
}

template<typename E> 
list<Position<E> > Tree<E>::positions() const {
    return positionNodes;
}

template<typename E> 
void Tree<E>::addPosition(Position<E> position) {
    positionNodes.push_back(position);
}

template class Position<int>;
template class Tree<int>;

template class Position<double>;
template class Tree<double>;

template class Position<string>;
template class Tree<string>;