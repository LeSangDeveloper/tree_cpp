#ifndef TREE_H
#define TREE_H

#include<list>

template<typename E>
struct Node<E> {
    E elem;
    Position parent;
    PositionList children;
}

template<typename E>
class Position<E> {
    private:
        Node* v;
    public:
        E& operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;
};
template<typename E>
typedef std::list<Position<E>> PositionList;

template<typename E>
class Tree<E> {
    private:
        Position root;
        PositionList positions;
    public:
        class Position;
        class PositionList;
    public:
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList positions() const;
}

#endif