

#ifndef NODE_H
#define NODE_H


#include <iostream>

#define T(i) template<class i>

T(T)
class Node
{
private:
    Node<T> *next, *prev;
    T data;

public:
    Node();
    Node(T);

    void setData(T);
    void setNext(Node<T>*);
    void setPrev(Node<T>*);

    const T& getData() const;
    Node<T>* getNext() const;
    Node<T>* getPrev() const;
};

#include "node.cpp"


#endif //NODE_H
