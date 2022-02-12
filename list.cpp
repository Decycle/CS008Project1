
#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

// Search for Node Function
T(T)
Node<T>* LinkedList<T>::findItem(const T& item)
{
    Node<T> *walker = head;
    for (walker; (walker != nullptr) && (walker->getData() != item); walker = walker->getNext());
    return walker;
}

// Getter - Head*
T(T)
const Node<T>* LinkedList<T>::getHead() const {return head;}

// Getter - Tail*
T(T)
const Node<T>* LinkedList<T>::getTail() const {return tail;}

// Private - Insert After Node
T(T)
void LinkedList<T>::insertAfter(Node<T>* node, T item)
{
    Node<T> *newNode = new Node<T>(item);
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }
    if (node == tail)
    {
        makeNewNode(item);
        return;
    }
    if (node->getNext() == tail)
    {
        newNode->setNext(tail);
        node->setNext(newNode);
        node = newNode;
    }
    else if (node->getNext() != nullptr)
    {
        newNode->setNext(node->getNext());
        newNode->setPrev(node);
        node->setNext(newNode);
        node->setPrev(newNode->getPrev());

    }
}

// Private - Insert Before Node
T(T)
void LinkedList<T>::insertBefore(Node<T>* node, T item)
{
    Node<T> *newNode = new Node<T>(item);
    Node<T> *prev = node->getPrev();
    if (head == nullptr)
    {
        head = tail = newNode;
        return;
    }
    else if (node == head)
    {
        insertBegin(item);
        return;
    }
    else if (node != nullptr)
    {
        newNode->setNext(node);
        node->setPrev(newNode);
        newNode->setPrev(prev);
        prev->setNext(newNode);
    }
}

// Private - Delete Node
T(T)
void LinkedList<T>::deleteNode(Node<T> *node)
{
    if (node == head)
    {
        deleteHead();
        return;
    }
    if (node == tail)
    {
        deleteTail();
        return;
    }
    if (node == nullptr)
    {
        return;
    }
    Node<T> *next = node->getNext();
    Node<T> *prev = node->getPrev();
    //if only one node
    if (head == tail)
    {
        head = tail = nullptr;
    }
    //if node is not begin  and not end
    else if (node != tail && node != head)
    {
        next->setPrev(prev);
        prev->setNext(next);
    }
    delete node;
}

// Private - Delete Head
T(T)
void LinkedList<T>::deleteHead()
{
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    head = head->getNext();
    delete head->getPrev();
    head->setPrev(nullptr);
}

// Private - Delete Tail
T(T)
void LinkedList<T>::deleteTail()
{
    if (tail == head && tail != nullptr)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        tail = tail->getPrev();
        delete tail->getNext();
        tail->setNext(nullptr);
    }
}

// Iterator Begin
T(T)
Iterator<T> LinkedList<T>::begin()
{
    itr temp(head);
    return temp;
}

// Iterator End
T(T)
Iterator<T> LinkedList<T>::end()
{
    itr temp;
    return temp;
}

// Default Constructor
T(T)
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// T Constructor
T(T)
LinkedList<T>::LinkedList(T input) {makeNewNode(input);}

// Copy Constructor
T(T)
LinkedList<T>::LinkedList(const LinkedList<T>& List)
{
    Node<T> copy;
    for (Node<T> *temp = List.head, *node = &copy; temp; temp = temp->getNext())
    {
        node->setNext(new Node<T>(temp->getData()));
        node = node->getNext();
    }
    this->head = copy.getNext();
}

// Deconstructor
T(T)
LinkedList<T>::~LinkedList()
{
    Node<T> *node = head;
    Node<T> *temp = new Node<T>;

    while (node)
    {
        temp = node;
        node = node->getNext();
        delete temp;
    }
}

// += Operator Overload
T(T)
LinkedList<T>& LinkedList<T>::operator+=(T data)
{
makeNewNode(data);
return *this;
}

// << Operator Overload
T(T)
std::ostream& operator<<(std::ostream &out, const LinkedList<T> &List)
{
    for (Node<T>* I = List.head; I != nullptr; I = I->getNext())
    {
        out << I->getData() << " ";
    }
    return out;
}

// List Size
T(T)
int LinkedList<T>::listSize() const
{
    if (head == nullptr || tail == nullptr)
        return 0;
    Node<T> *temp = head;
    int count = 1;
    while (temp->getNext() != nullptr)
    {
        ++count;
        // go to next node
        temp = temp->getNext();
    }
    return count;
}

// Is or not Empty
T(T)
bool LinkedList<T>::isEmpty() const {return head == nullptr;}

// Make New Node
T(T)
void LinkedList<T>::makeNewNode(T value)
{
    //new node
    Node<T> *temp = new Node<T>;
    //set new node data
    temp->setData(value);
    //set new node next
    temp->setNext(nullptr);
    temp->setPrev(tail);
    if (tail == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->setNext(temp);
        tail = temp;
    }
}

// Public - Insert at head
T(T)
void LinkedList<T>::insertBegin(T value)
{
//new node
Node<T> *temp = new Node<T>;

//new node data set
temp->setData(value);
//set to next to old head, head initializes as nullptr
temp->setNext(head);
//set prev to nullptr since new head
temp->setPrev(nullptr);
//h
if (listSize() > 1 && head->getPrev() == nullptr)
    head->setPrev(temp);

//finalize new head
head = temp;
}

// Public - Insert at head
T(T)
void LinkedList<T>::insertEnd(T value)
{
    insertAfter(tail,value);
}

// Public - Before After Node
T(T)
void LinkedList<T>::insertBefore(T search, T item)
{
Node<T>* ptrNode = findItem(search);
insertBefore(ptrNode, item);
}

// Public - Insert After Node
T(T)
void LinkedList<T>::insertAfter(T search, T item)
{
Node<T>* ptrNode = findItem(search);
insertAfter(ptrNode, item);
}

// Public - Delete Node
T(T)
void LinkedList<T>::deleteNode(T item)
{
Node<T> *temp = findItem(item);
if (temp != nullptr)
deleteNode(temp);
}

// Public - Clear List
T(T)
void LinkedList<T>::clearList()
{
    Node<T> *temp = head;
    while (temp->getNext())
    {
        temp = head->getNext();
        delete head;
        head = temp;
        //set previous of head to null
        head->setPrev(nullptr);
    }
    head = tail = nullptr;
}
#endif //LIST_CPP
