
#ifndef STACK_ITERATOR_CPP
#define STACK_ITERATOR_CPP
#include "iterator.h"

// Next Node
T(T)
Iterator<T>* Iterator<T>::iterateNext()
{
    return current->getNext();
}

// Current Address-Pointer
T(T)
Node<T>* Iterator<T>::getCurrent()
{
    return current;
}

// Constructor, default
T(T)
Iterator<T>::Iterator() : current(nullptr)
{
}

// Constructor, pointer argument
T(T)
Iterator<T>::Iterator(Node<T>* node)
{
    current = node;
}

// Copy Constructor
T(T)
Iterator<T>::Iterator(const Node<T>& node)
{
    current = node;
}

// Deconstructor
T(T)
Iterator<T>::~Iterator()
{
    current = nullptr;
}

// prefix
T(T)
Iterator<T>& Iterator<T>::operator++()
{
    if (current != nullptr)
        current = current->getNext();

    return *this;
}

// postfix
T(T)
Iterator<T> Iterator<T>::operator++(int i)
{
    Iterator<T>* previous(current);
    current = current->getNext();
    return *this;
}

// prefix
T(T)
Iterator<T>& Iterator<T>::operator--()
{
    current = current->getPrev();
    return *this;
}

// postfix
T(T)
Iterator<T> Iterator<T>::operator--(int i)
{
    Iterator<T>* previous(current);
    current = current->getPrev();
    return previous;
}

// += Overload
T(T)
Iterator<T>& Iterator<T>::operator+=(unsigned int index)
{
    Node<T>* walker = current;
    int count = 0;
    while (walker->getNext() != nullptr && count < index)
    {
        walker = walker->getNext();
        ++count;
    }
    current = walker;
    return *this;
}

// -=
T(T)
Iterator<T>& Iterator<T>::operator-=(unsigned int index)
{
    Node<T>* walker = current;
    int count = 0;
    while (walker->getPrev() != nullptr && count < index)
    {
        walker = walker->getPrev();
        ++count;
    }
    current = walker;
    return *this;
}

// dereferences
T(T)
const T Iterator<T>::operator*() const
{
    return current->getData();
}

 //Bracket overload
 template<class T>
 const T& Iterator<T>::operator[](unsigned int item)
 {
     Node<T>* walker = current;
     while (walker != nullptr)
     {
         if (walker->getData() == item)
             return item;
         else walker = walker->getNext();
     }
     item = walker->getData();
     return item; //find node
 }

// = Assignment Operator
T(T)
Iterator<T>& Iterator<T>::operator=(T item)
{
    return current = current(item);
}

// =/= Overload
T(T)
bool Iterator<T>::operator!=(const Iterator<T> &itr)
{
    return current != itr.current;
}

// == Overload
T(T)
bool Iterator<T>::operator==(const Iterator<T> *itr)
{
    return current == itr;
}

template<class T>
Iterator<T> Iterator<T>::operator-(unsigned int places)
{
    Node<T>* walker = current;
    int count = 0;
    while (walker->getPrev() != nullptr && count < places)
    {
        walker = walker->getPrev();
        ++count;
    }
    return walker;
}

template<class T>
Iterator<T> Iterator<T>::operator+(unsigned int places) {
    //walker node
    Node<T>* walker = current;
    //count from 0
    int count = 0;
    while (walker->getNext() != nullptr && count < places)
    {
        walker = walker->getNext();
        ++count;
    }
    return walker;
}

#endif //STACK_ITERATOR_CPP
