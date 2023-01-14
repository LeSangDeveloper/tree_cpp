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
        void setParent(Position<E>* parent);
        void addChild(Position<E> child);
        Position<E> parent() const;
        std::list<Position<E> > children() const;
        bool isRoot() const;
        bool isExternal() const;
};

template<typename E>
class Tree {
    private:
        Position<E> *rootNode;
        std::list<Position<E> > positionNodes;
    public:   
        Tree()
        : rootNode(NULL) {}
        Tree(Position<E>* root)
        : rootNode(root) {}
        Tree(Position<E> root)
        : rootNode(&root) {}
        void addPosition(Position<E> position);
        int size() const;
        bool empty() const;
        Position<E> root() const;
        std::list<Position<E> > positions() const;
};

#endif