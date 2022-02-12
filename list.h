
#ifndef LIST_H
#define LIST_H


#include "iterator.h"

T(T)
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;


    const Node<T>* getHead() const;
    const Node<T>* getTail() const;
    void insertAfter(Node<T>*, T);
    void insertBefore(Node<T>*, T);
    void deleteNode(Node<T>*);
    void deleteHead();
    void deleteTail();

public:
    typedef Iterator<T> itr;
    itr begin();
    itr end();
    LinkedList();
    LinkedList(T);
    //for copy
    LinkedList(const LinkedList<T>&);

    ~LinkedList();

    LinkedList<T>& operator+=(T);


    void makeNewNode(T);

    //Insert an item at the beginning of the list
    void insertBegin(T);
    //Insert an item at the end of the list
    void insertEnd(T);
    ////Insert an item in the middle of the list
    //Insert before a particular node
    void insertBefore(T, T);
    //Insert after a particular node
    void insertAfter(T, T);
    //Find an item
    Node<T>* findItem(const T&);
    //Remove an item
    void deleteNode(T);
    //Check if the list is empty
    bool isEmpty() const;
    //Check the size of the list
    int listSize() const;
    //Clear the list
    void clearList();
    //Copy the list

    //print all items in the list
    T(S)
    friend std::ostream& operator<<(std::ostream&, const LinkedList<S>&);
};

#include "list.cpp"


#endif //LIST_H
