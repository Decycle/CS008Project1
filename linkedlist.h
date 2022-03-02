#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "listempty.h"
#include <string>
#include <sstream>

//using namespace std;

// Linked List nodes
template<class E>
struct Node{
    E data;
    Node *next;
    Node( E data ) : data(data), next(0) {}
};

/**************************************************************************
* Iterator Class
*      This class is used as iterators for the list class. Can check if
* equal or not equal. Could increment and increment.
**************************************************************************/
template<class E>
class Iterator
{
private:
    Node<E>* current;               //PROC- contained list
public:
    Iterator();

    Iterator(Node<E> *ptr);

    E operator*();

    Iterator operator++();

    Iterator operator--();

    bool operator==(const Iterator& right) const;

    bool operator!=(const Iterator& right) const;

};
/**********************************************************************
 * Iterator();
 *      Constructor; Initialize the iterator.
 *---------------------------------------------------------------------
 *      Parameters: none
 *---------------------------------------------------------------------
 *      Return: none
 *********************************************************************/
/**********************************************************************
 * Iterator(Node<E> *ptr);
 *      Constructor; Initialize the iterator with the pointer passed.
 *---------------------------------------------------------------------
 *      Parameters: ptr     // Node<E>
 *---------------------------------------------------------------------
 *      Return: none
 *********************************************************************/
/**********************************************************************
 * int operator*();
 *      Accessor; overloads the dereferencing operator*
 *---------------------------------------------------------------------
 *      Parameters: none
 *---------------------------------------------------------------------
 *      Return: should return the info contained in the node.
 *********************************************************************/
/**********************************************************************
 * Iterator operator++();
 *      Constructor; overloads the pre-increment operator++
 *---------------------------------------------------------------------
 *      Parameters: none
 *---------------------------------------------------------------------
 *      Return: should return an iterator pointing to the next node.
 *********************************************************************/
/**********************************************************************
 * Iterator operator--();
 *      Accessor; overloads the pre-decrement operator--
 *---------------------------------------------------------------------
 *      Parameters: none
 *---------------------------------------------------------------------
 *      Return: should return iterator that is pointing to the previous
 *      node
 *********************************************************************/
/**********************************************************************
 * bool operator==(const Iterator& right) const;
 *      Constructor; overloads the equality operator
 *---------------------------------------------------------------------
 *      Parameters:     right           // Iterator
 *---------------------------------------------------------------------
 *      Return: Should return true if this iterator is equal to the
 *      iterator specified by right, otherwise it returns false.
 *********************************************************************/
/**********************************************************************
 * bool operator!=(const Iterator& right) const;
 *      Constructor; overloads the not equal to operator
 *---------------------------------------------------------------------
 *      Parameters:     right           // Iterator
 *---------------------------------------------------------------------
 *      Return: Should return true if this iterator is not equal to the
 *      iterator specified by right, otherwise it returns false.
 *********************************************************************/


/**************************************************************************
* LinkedList Class
*      This class represents linked lists as objects. Has functions that
*      can be done on any LinkedList objects created.
*
**************************************************************************/
template<class E>
class LinkedList: public Iterator<E>
{
    private:
        Node<E>* head;                              //PROC- list front node
        Node<E>* tail;                              //PROC- list back node

    public:
        LinkedList();

        LinkedList(const LinkedList<E> &source);

        LinkedList<E>& operator=(const LinkedList<E>& source);

        ~LinkedList();

        const E& front() const;

        const E& back() const;

        Iterator<E> begin();

        Iterator<E> end();

        int length() const;

        int sum() const;

        bool isEmpty() const;

        std::string display() const;

        std::string partial_display(unsigned start, unsigned end) const;

        void push_front(const E& value);

        void push_back(const E& value);

        void pop_front();

        void pop_back();

        void clear();

        void insert_nth(E& data, int pos);

        void delete_nth(int pos);

        Node<E>& GetN(unsigned index);

        E& operator[](const unsigned i);

        void operator+=(const LinkedList<E> &other);

};
/******************
 **  CONSTRUCTORS  **
 ******************/
/******************************************************************
 * LinkedList();
 *      Constructor; Initialize an empty LinkedList.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * LinkedList(const LinkedList<E>& source);
 *      Constructor; Called when a LinkedList is declared and
 * initialized using an existing LinkedList.
 *-----------------------------------------------------------------
 *      Parameters:
 *              source          // LinkedList
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/

/***************************
 **  ASSIGNMENT OPERATOR  **
 ****************************/
/******************************************************************
  * LinkedList<E> & operator=(const LinkedList<E>& source);
  *      Constructor; Called when using the assignment operator to
  *      set one
  *      LinkedList equal to another.
  *----------------------------------------------------------------
  *      Parameters:
 *              source          // LinkedList
  *----------------------------------------------------------------
  *      Return: none
  ****************************************************************/
/******************
 **  DESTRUCTOR  **
 ******************/
/******************************************************************
 * ~LinkedList();
 *      Destructor; This function should deallocate all remaining
 *      dynamically allocated memory (all remaining Nodes).
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************
 **  ACCESSORS  **
 ******************/
/******************************************************************
 * const E& front() const throw(ListEmpty);
 *      Accessor; Returns the element at the head of the LinkedList.
 *      Exception handling if the list is empty.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * const E& back() const throw(ListEmpty);
 *      Accessor; Returns the element at the tail of the LinkedList.
 *      Exception handling if the list is empty.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * Iterator<E> begin();
 *      Accessor; This function returns an iterator at the
 * beginning of the linked list.  Returns an iterator pointing to
 * head.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: return Iterator<E>(head);
 *****************************************************************/
/******************************************************************
 * Iterator<E> end();
 *      Accessor; This function returns an iterator one element
 *      past the last element of the linked list.  Returns an
 *      iterator pointing to NULL.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: return Iterator<E>(nullptr);
 *****************************************************************/
/******************************************************************
 * int length() const;
 *      Accessor; This function recursively determines the length
 * of the list.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: returns 0 or 1 + length()
 *****************************************************************/
/******************************************************************
 * E sum() const;
 *      Accessor; This function recursively calculates the sum of
 *      all of the elements in the list.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: returns 0 or current->data + sum()
 *****************************************************************/
/******************************************************************
 * bool isEmpty() const;
 *      Accessor; This function sees whether this list is empty.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: return head == nullptr;
 *****************************************************************/
/******************************************************************
 * std::string display() const;
 *      Accessor; Displays the contents of the LinkedList.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * std::string partial_display(unsigned start, unsigned end) const;
 *      Accessor; shows the contents of the LinkedList as a string.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * Node<E>& GetN(unsigned index);
 *      accessor; This function gets the node of the index given.
 *-----------------------------------------------------------------
 *      Parameters:
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * E operator[](const unsigned i);
 *      Accessor; This operator gives the spcific element of the
 *      index given inside the bracket
 *-----------------------------------------------------------------
 *      Parameters:   i  // index value
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************
 **  MUTATORS  **
 ******************/
/******************************************************************
 * void push_front(const E& value);
 *      Mutator; This function inserts a data value
 *      (within a new node) at the front end of the list.
 *-----------------------------------------------------------------
 *      Parameters:   value   // value to be added at front of node
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * void push_back(const E& value);
 *      Mutator; This function inserts a data value (within a new
 *      node) at the back end of the list.
 *-----------------------------------------------------------------
 *      Parameters:   value   // value to be added at back of node
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * void pop_front() throw(ListEmpty);
 *      Mutator; This function removes the value (actually removes
 *      the node that contains the value) at the front end of the
 *      list. Exception handling if the list is empty.
 *-----------------------------------------------------------------
 *      Parameters: ListEmpty // if the list is empty
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * void pop_back() throw(ListEmpty);
 *      Mutator; This function removes the value (actually removes
 *      the node that contains the value) at the back end of the
 *      list. Exception handling if the list is empty.
 *-----------------------------------------------------------------
 *      Parameters: ListEmpty // if the list is empty
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * void clear();
 *      Mutator; This function makes the List Empty by deallocating
 *      all of the nodes in the List.
 *-----------------------------------------------------------------
 *      Parameters: none
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
/******************************************************************
 * void insert_nth(E data, int pos);
 *      Mutator; Inserts data at index position of linked list.
 *-----------------------------------------------------------------
 *      Parameters:
 *      E data
 *      int pos
 *-----------------------------------------------------------------
 *      Return: none
 *****************************************************************/
//--------------------------------------------------------------------------------------
#endif // LINKEDLIST_H
