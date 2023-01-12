#ifndef TREE_H
#define TREE_H

#include<list>

template<typename E>
class Position<E> {
    E& operator*();
    Position parent() const;
    PositionList children() const;
    bool isRoot() const;
    bool isExternal() const;
};
typedef std::list<Position> PositionList;

template<typename E>
class Tree<E> {
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