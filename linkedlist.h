#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include "listempty.h"
using namespace std;

template <typename E>
struct Node
{
    E data;     //value in the node
    Node *next; //pointer to the next node
    /***************
     **CONSTRUCTOR**
     **************/
    Node(E data) : data(data), next(0) {}
    //constructor, initialises node with value
};

template <typename E>
class LinkedList
{
public:
    /***************
    **CONSTRUCTOR**
    **************/
    LinkedList();                         //initialises class with head
                                          //and tail to NULL
    LinkedList(const LinkedList &source); //initialises linked list with
                                          //another one

    /**************
    **DESTRUCTOR**
    **************/
    virtual ~LinkedList(); //deletes the values in object
                           //starting with head

    /************
    **ACCESSOR**
    ************/
    void display() const; //print to console
    // Iterator begin();     //returns a iterator at the first node
    // Iterator end();       //returns a iterator pointing to NULL

    const E &front() const; //return the first item
                            // in the list
    const E &back() const;  //return the last item
                            // in the list

    int length() const;   //returns the length of the list
    E sum() const;        //returns the sum of the list
    bool isEmpty() const; //returns if the list is empty

    /***********
    **MUTATOR**
    ***********/
    void push_front(const E &value); //new Node at head
    void push_back(const E &value);  //new Node at tail

    void pop_front(); //removes Node at head, next Node
                      // becomes head. If empty, throw error

    void clear(); //clear the list

    void select_sort(); //sorts the list into ascending order
                        //using the selection sort algorithm

    void insert_sorted(int value); //inserts the data into the
                                   //appropriate position in the list

    void remove_duplicates(); //removes all values and the nodes
                              //that are duplicates of a value
                              //that already exists in the list.

    LinkedList &operator=(const LinkedList &source);
    //overload the assign operator

private:
    Node<E> *head; //first element in the list, type Node
    Node<E> *tail; //last element in the list

    int get_length(Node<E> *head) const; //helper function to get
                                         //length of the list
                                         //recursively

    E get_sum(Node<E> *head) const; //helper function to get sum of the
                                    //list recursively
};

#endif // LINKEDLIST_H
