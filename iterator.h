
#ifndef ITERATOR_H
#define ITERATOR_H


#include "node.h"
#include <iterator>

T(T)
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
private:
    Node<T>* current;
    Iterator<T>* iterateNext();
    Node<T>* getCurrent();

public:
    Iterator();
    Iterator(Node<T>*);
    Iterator(const Node<T>&);
    ~Iterator();

    Iterator<T>& operator++();        //prefix
    Iterator<T> operator++(int);      //postfix
    Iterator<T>& operator--();        //prefix
    Iterator<T> operator--(int);      //postfix

    Iterator<T>& operator+=(unsigned int index);
    Iterator<T>& operator-=(unsigned int index);

    const T operator*() const;
    const T& operator[](unsigned int);

    Iterator<T>& operator=(T);

    bool operator!=(const Iterator<T>&);
    bool operator==(const Iterator<T>*);

    Iterator<T> operator-(unsigned int places);
    Iterator<T> operator+(unsigned int places);
};

#include "iterator.cpp"


#endif //ITERATOR_H
