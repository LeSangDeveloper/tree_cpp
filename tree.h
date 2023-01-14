#ifndef TREE_H
#define TREE_H

#include<list>

template<typename E>
class Position {
    private:
        E elem;
        Position<E>* parentPos;
        std::list<Position<E> > childrenPos;
    public:
        Position() 
        :parentPos(NULL) {}
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