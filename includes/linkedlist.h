#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "listempty.h"
#include <string>
#include <sstream>

// using namespace std;

// Linked List nodes
template <class E>
struct Node
{
    E data;
    Node *next;
    Node(E data) : data(data), next(0) {}
};

/**************************************************************************
 * Iterator Class
 *      This class is used as iterators for the list class. Can check if
 * equal or not equal. Could increment and increment.
 **************************************************************************/
template <class E>
class Iterator
{
private:
    Node<E> *current; // PROC- contained list
public:
    Iterator();

    Iterator(Node<E> *ptr);

    E operator*();

    Iterator operator++();

    Iterator operator--();

    bool operator==(const Iterator &right) const;

    bool operator!=(const Iterator &right) const;
};

template <class E>
class LinkedList : public Iterator<E>
{
private:
    Node<E> *head; // PROC- list front node
    Node<E> *tail; // PROC- list back node

public:
    LinkedList();

    LinkedList(const LinkedList<E> &source);

    LinkedList<E> &operator=(const LinkedList<E> &source);

    ~LinkedList();

    const E &front() const;

    const E &back() const;

    Iterator<E> begin();

    Iterator<E> end();

    int length() const;

    int sum() const;

    bool isEmpty() const;

    std::string display() const;

    std::string partial_display(unsigned start, unsigned end) const;

    void push_front(const E &value);

    void push_back(const E &value);

    void pop_front();

    void pop_back();

    void clear();

    void insert_nth(E data, int pos);

    Node<E> &GetN(unsigned index);

    E &operator[](const unsigned i);
};

//--------------------------------------------------------------------------------------

template <class E>
Iterator<E>::Iterator()
{
    // PROC-initialize iterator
    current = nullptr;
}

template <class E>
Iterator<E>::Iterator(Node<E> *ptr) // Node<E>
{
    // PROC-set iterator to pointer
    current = ptr;
}

template <class E>
E Iterator<E>::operator*()
{
    // PROC-get value of iterator node
    return current->data;
}

template <class E>
Iterator<E> Iterator<E>::operator++()
{
    // PROC-gets next node/iterator
    return current = current->next;
}

template <class E>
Iterator<E> Iterator<E>::operator--()
{
    // PROC-goes to previous iterator
    return current = current->prev;
}

template <class E>
bool Iterator<E>::operator==(const Iterator &right // PROC-right iterator
) const
{
    // PROC-returns bool for node == node
    return current == right.current;
}

template <class E>
bool Iterator<E>::operator!=(const Iterator &right) const // iterator
{
    // PROC-returns bool for node != node
    return current != right.current;
}

template <class E>
LinkedList<E>::LinkedList() : head(nullptr) // PROC- initialize blank head
                              ,
                              tail(nullptr) // PROC- initialize blank tail
{
    // std::cout << "using Sean L's Linked list\n";
}

template <class E>
LinkedList<E>::LinkedList(const LinkedList<E> &source // PROC-source to copy
                          ) : head(nullptr), tail(nullptr)
{
    // PROC- if list isnt empty
    if (head == nullptr)
    {
        // PROC- set head and tail
        head = new Node<E>(*source.head);
        tail = new Node<E>(*source.tail);
    }
    else
    {
        // PROC- go to next node until tail
        tail->next = new Node<E>(*source.head);
        // PROC- set as tail
        tail = new Node<E>(*source.tail);
    }
}

template <class E>
LinkedList<E>::~LinkedList()
{
    // PROC-clear contents
    clear();
    head == nullptr;
    tail == nullptr;
}

template <class E>
E &LinkedList<E>::operator[](const unsigned i)
{
    Node<E> *walker = head;
    for (int j = 0; j < i; j++)
    {
        walker = walker->next;
    }
    return walker->data;
}

template <class E>
LinkedList<E> &LinkedList<E>::operator=(const LinkedList<E> &source // List
)
{

    Node<E> *head2; // PROC-temp head node
    Node<E> *tail2; // PROC-temp tail node
    // PROC-set node
    head2 = source.head;

    // PROC-if list is equal
    if (this == &source)
        // OUT-set self
        return *this;

    // PROC-if both lists are not empty
    if (head != nullptr && head2 != nullptr)
        clear();

    // PROC-if list is not blank
    if (head2 != nullptr)
    {
        // PROC-set head value
        head = new Node<E>(head2->data);
    }

    // PROC-set head value
    tail2 = head;

    // PROC-until head node doesnt reach end
    while (head2 != nullptr)
    {
        // PROC-go to next node
        head2 = head2->next;
        // PROC-if not at end
        if (head2 != nullptr)
        {
            // PROC-set next node
            tail2->next = new Node<E>(head2->data);
            // PROC-go to next node
            tail2 = tail2->next;
        }
    }
    // PROC-set tail value
    tail = tail2;
    // OUT-set self
    return *this;
}

template <class E>
std::string LinkedList<E>::display() const
{
    stringstream out;
    Node<E> *temp; // PROC- New Node
    temp = head;   // PROC- set to head
    // PROC- until not at end of list
    while (temp != nullptr)
    {
        // PROC- print current node
        out << temp->data;
        // PROC- go to next node
        temp = temp->next;
        // PROC- until not at end
        if (temp != nullptr)
        {
            // PROC- space the printed nodes as passed
            out << ' ';
        }
    }
    return out.str();
}

template <class E>
string LinkedList<E>::partial_display(unsigned start, unsigned end) const
{

    unsigned count = 1; // start min is 1

    Node<E> *temp = head;

    string tempo;
    stringstream send;
    send.clear();
    // PROC- New Node                            //PROC- set to head
    // PROC- until not at end of list
    for (int i = 0; i < length(); i++)
    {
        if (count >= start && count <= end)
        {
            // PROC- print current node
            send << (temp->data);
            send << "";
        }
        // PROC- go to next node
        temp = temp->next;
        // PROC- until not at cout
        //--------------------
        count++;
    }
    return (send.str());
}

template <class E>
void LinkedList<E>::push_front(const E &value // INPUT- to push front
)

{
    // PROC-if empty
    if (head == nullptr)
    {
        // PROC-sets front node
        head = new Node<E>(value);
    }
    else // if not empty
    {
        Node<E> *temp; // PROC- New Node
        // PROC-set temp node
        temp = new Node<E>(value);
        // PROC-go to next node
        temp->next = head;
        // PROC-set head to temp until at end of list
        head = temp;
    }
}

template <class E>
void LinkedList<E>::push_back(const E &value)
{

    Node<E> *hold = new Node<E>(value);
    hold->next = head;
    head = hold;

    //    Node<E>* walker = head;
    //    //PROC-if empty
    //    if (head == nullptr)
    //    {
    //        //PROC-sets front node
    //        head = new Node<E>(value);
    //    }
    //    else//if not empty
    //    {
    //        Node<E>* temp;                              //PROC- New Node
    //        //PROC-set temp node
    //        temp = new Node<E>(value);
    //        //while next node is not last
    //        while(walker->next != nullptr)
    //            walker=walker->next;
    //
    //        walker->next = temp;
    //    }
}

template <class E>
void LinkedList<E>::pop_front() // PROC- if list is empty
{
    // PROC-exception if list is empty
    if (isEmpty())
        // PROC- throw
        throw ListEmpty("List is Empty\n");
    else if (length() == 1)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else if (length() > 1)
    {
        Node<E> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class E>
void LinkedList<E>::pop_back() // PROC- if list is empty
{
    // PROC-exception if list is empty
    if (isEmpty())
        // PROC- throw
        throw ListEmpty("List is Empty\n");
    else if (length() == 1)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else if (length() > 1)
    {
        Node<E> *beforeWalker;
        Node<E> *walker = head;
        while (walker->next != nullptr)
        {
            beforeWalker = walker;
            walker = walker->next;
        }
        delete walker;
        beforeWalker->next = nullptr;
    }
}

template <class E>
const E &LinkedList<E>::front() const // PROC- if list empty
{
    // PROC- if empty
    if (isEmpty())
        // PROC- go through exception
        throw ListEmpty("List is Empty\n");
    else
        // PROC- return front node value
        return head->data;
}

template <class E>
const E &LinkedList<E>::back() const // PROC- if list empty
{
    // PROC- if empty
    if (isEmpty())
        // PROC- go through exception
        throw ListEmpty("List is Empty\n");
    else
        // PROC- return back node value
        return tail->data;
}

template <class E>
void LinkedList<E>::clear()
{
    while (!isEmpty())
    {
        pop_front();
    }
}

template <class E>
void LinkedList<E>::insert_nth(E data, int position)
{
    Node<E> *temp1 = new Node<E>(data);

    temp1->data = data; // set value of node
    temp1->next = NULL;

    if (position == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node<E> *temp2 = head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

template <class E>
Iterator<E> LinkedList<E>::begin()
{
    // PROC-return front of iterator
    return Iterator<E>(LinkedList<E>::front());
}

template <class E>
Iterator<E> LinkedList<E>::end()
{
    // PROC-return back of iterator
    return Iterator<E>(LinkedList<E>::back());
}

template <typename E>
int LinkedList<E>::length() const
{
    int count = 0;
    Node<E> *walker = head;
    // if empty
    if (walker == nullptr)
        return 0;
    // if 1 node
    if (walker != nullptr && walker->next == nullptr)
        return 1;
    // PROC-while not at last element and not empty
    while (walker != nullptr)
    {
        walker = walker->next;
        count++;
    }
    return count;
}

template <class E>
int LinkedList<E>::sum() const
{
    Node<E> *temp; // PR0C-Temp Node
    temp = head;   // PROC-Set temp

    // PROC-if list is empty
    if (head == nullptr)
        return 0;
    else
    {
        // PROC-while not at end of list
        while (temp != nullptr)
        {
            // PROC-go to next node
            temp = temp->next;
            // PROC-add and recursively add next node
            return temp->data + sum();
        }
    }
}

template <class E>
bool LinkedList<E>::isEmpty() const
{
    // PROC-if empty
    return (head == nullptr && tail == nullptr);
}

template <class E>
Node<E> &LinkedList<E>::GetN(unsigned index)
{
    unsigned count = 0;
    Node<E> *temp = head;
    while (temp != nullptr)
    {
        if (count == index)
            return (temp->data);
        count++;
        temp = temp->next;
    }
}
#endif // LINKEDLIST_H
