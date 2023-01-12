#ifndef TREE_H
#define TREE_H

#include<list>

template<typename E>
class Position;

template<typename E>
struct Node {
    E elem;
    Position<E> parent;
    std::list<Position<E> > children;
};

template<typename E>
class Position {
    private:
        Node<E>* v;
    public:
        E& operator*();
        Position<E> parent() const;
        std::list<Position<E> > children() const;
        bool isRoot() const;
        bool isExternal() const;
};

template<typename E>
class Tree {
    private:
        Position<E> rootNode;
        std::list<Position<E> > positionNodes;
    public:
        int size() const;
        bool empty() const;
        Position<E> root() const;
        std::list<Position<E> > positions() const;
};

#endif