#include "linkedlist.h"
/***************
 **CONSTRUCTOR**
 **************/

/*************************************************
* Method LinkedList(): Class LinkedList
*_________________________________________________
* Constructor that initialises an LinkedList
* object with head and tail at NULL (list empty)
*________________________________________________
* PRE-CONDITIONS
* The following needs previous defined values:
* none
* POST-CONDITIONS
* Creates an LinkedList with a defined head and tail
* of NULL
*************************************************/
template <typename E>
LinkedList<E>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

/*************************************************
* Method LinkedList(): Class LinkedList
*_________________________________________________
* Constructor that initialize a new list with the
* contents of an existing list.
*________________________________________________
* PRE-CONDITIONS:
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* Creates an LinkedList with a defined head and tail
* that is the same as the provided one.
*************************************************/
template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E> &list)
{
    head = new Node<E>(list.head->data);

    Node<E> *copy = list.head->next;
    Node<E> *old = new Node<E>(list.head->next->data);

    head->next = old;

    while (copy != list.tail)
    {
        old->next = new Node<E>(copy->next->data);

        copy = copy->next;
        old = old->next;
    }
}

/**************
 **DESTRUCTOR**
 **************/

/*************************************************
* Method ~LinkedList(): Class LinkedList
*_________________________________________________
* Destructor that deletes the elements in the
* ordered list LinkedList object by going down the
* head's pointer across all pointers until hitting
* NULL and deleting (deallocating) all nodes
*________________________________________________
* PRE-CONDITIONS:
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* deconstructs LinkedList, deletes Nodes pointed to
*************************************************/
template <typename E>
LinkedList<E>::~LinkedList()
{
    Node<E> *current = head;
    while (current)
    {
        current = current->next;
        delete head;
        head = current;
    }
}

/************
 **ACCESSOR**
 ************/

/*************************************************
* Method display(): Class LinkedList
*_________________________________________________
* Goes down the head's pointer across all pointers
* pointed at, and outputs to console all .data
* in the Nodes pointed at
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, display function
*************************************************/
template <typename E>
void LinkedList<E>::display() const
{
    Node<E> *current;
    current = head;
    while (current)
    {
        cout << current->data;
        current = current->next;
        if (current)
            cout << " ";
    }
}
/*************************************************
* Method begin(): Class LinkedList
*_________________________________________________
* Returns an iterator at the beginning of the linked
* list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns an iterator pointing to head.
*************************************************/
// Iterator LinkedList::begin()
// {
//     return Iterator(head);
// }

/*************************************************
* Method end(): Class LinkedList
*_________________________________________________
* Returns an iterator one element past the last
* element of the linked list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns an iterator pointing to NULL.
*************************************************/
// Iterator LinkedList::end()
// {
//     return Iterator(tail->next);
// }

/*************************************************
* Method front(): Class LinkedList
*_________________________________________________
* Returns the data in the head of the linked list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the data in the head of the linked list.
*************************************************/
template <typename E>
const E &LinkedList<E>::front() const
{
    try
    {
        return head->data;
    }
    catch (ListEmpty e)
    {
        throw e;
    }
}

/*************************************************
* Method back(): Class LinkedList
*_________________________________________________
* Returns the data in the tail of the linked list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the data in the tail of the linked list.
*************************************************/

template <typename E>
const E &LinkedList<E>::back() const
{
    try
    {
        return tail->data;
    }
    catch (ListEmpty e)
    {
        throw e;
    }
}

/*************************************************
* Method length(): Class LinkedList
*_________________________________________________
* Returns the length of the linked list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the length of the linked list.
*************************************************/
template <typename E>
int LinkedList<E>::length() const
{
    return get_length(head);
}

/*************************************************
* Method get_length(): Class LinkedList
*_________________________________________________
* Private helper function that returns the length
* of the linked list recursively.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the length of the linked list.
*************************************************/
template <typename E>
int LinkedList<E>::get_length(Node<E> *h) const
{
    if (h == NULL)
    {
        return 0;
    }

    return 1 + get_length(h->next);
}

/*************************************************
* Method sum(): Class LinkedList
*_________________________________________________
* Returns the sum of the linked list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the sum of the linked list.
*************************************************/
template <typename E>
E LinkedList<E>::sum() const
{
    return get_sum(head);
}

/*************************************************
* Method get_sum(): Class LinkedList
*_________________________________________________
* Private helper function that returns the sum
* of the linked list recursively.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns the sum of the linked list.
*************************************************/
template <typename E>
E LinkedList<E>::get_sum(Node<E> *h) const
{
    if (h == NULL)
    {
        return 0;
    }

    return h->data + get_sum(h->next);
}
/***********
 **MUTATOR**
 ***********/

/*************************************************
* Method push_front: Class LinkedList
*_________________________________________________
* Adds a new IntNode with the input data
* value to the front of the ordered list LinkedList,
* pointing to the old head and setting the new
* head to the new IntNode
* Ours also sets a new tail if the list is empty
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* value - data to add to ordered list's new node
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::push_front(const E &value)
{
    Node<E> *newNode;
    newNode = new Node<E>(value);
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
        tail = newNode;
}

/*************************************************
* Method push_back: Class LinkedList
*_________________________________________________
* Adds a new Node with the input data
* value at the end of the ordered list LinkedList,
* point the old tail to it and setting the new
* tail to the new Node
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* value - data to add to ordered list's new node
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::push_back(const E &value)
{
    Node<E> *newNode = new Node<E>(value);
    tail->next = newNode;
    tail = newNode;
}

/*************************************************
* Method pop_front: Class LinkedList
*_________________________________________________
* Removes the Node at the head of the ordered
* list LinkedList, deleting it and setting the new
* head to the next node, or NULL.
* If the list is not empty.
* Ours also sets the tail to NULL if the list
* becomes empty.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::pop_front()
{
    try
    {
        Node<E> *temp;
        temp = head->next;
        delete head;
        head = temp;
        if (head == NULL)
            tail = NULL;
    }
    catch (ListEmpty e)
    {
        throw e;
    }
}

/*************************************************
* Method select_sort: Class LinkedList
*_________________________________________________
* Sorts the list into ascending order using the
* selection sort algorithm.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::select_sort()
{
    Node<E> *current = head;

    while (current)
    {
        Node<E> *min = current;
        Node<E> *n = current->next;

        while (n)
        {
            if (min->data > n->data)
            {
                min = n;
            }
            n = n->next;
        }

        int tmp = current->data;
        current->data = min->data;
        min->data = tmp;

        current = current->next;
    }
}

/*************************************************
* Method insert_sorted: Class LinkedList
*_________________________________________________
* Assumes the values in the list are in sorted
* (ascending) order and inserts the data into the
* appropriate position in the list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The values in the list are sorted(ascending)
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::insert_sorted(int value)
{
    Node<E> *current = head;

    while (true)
    {
        if (current == NULL)
        {
            Node<E> *newNode = new Node<E>(value);
            tail->next = newNode;
            break;
        }

        if (value <= current->next->data)
        {
            Node<E> *newNode = new Node<E>(value);
            newNode->next = current->next;
            current->next = newNode;

            break;
        }
        current = current->next;
    }
}

/*************************************************
* Method insert_sorted: Class LinkedList
*_________________________________________________
* Removes all values and the nodes containing these
* values that are duplicates of a value that already
* exists in the list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
void LinkedList<E>::remove_duplicates()
{
    Node<E> *current = head;

    while (current)
    {
        Node<E> *n = current;

        while (n->next)
        {
            if (n->next->data == current->data)
            {
                Node<E> *next_node = n->next->next;
                delete n->next;
                n->next = next_node;
            }
            else
            {
                n = n->next;
            }
        }

        current = current->next;
    }
}

/*************************************************
* Method insert_sorted: Class LinkedList
*_________________________________________________
* Removes all values and the nodes containing these
* values that are duplicates of a value that already
* exists in the list.
*________________________________________________
* PRE-CONDITIONS:
* Accesses values in calling object
* The following needs previous defined values:
* none
* POST-CONDITIONS:
* returns nothing, modifies calling object
*************************************************/
template <typename E>
LinkedList<E> &LinkedList<E>::operator=(const LinkedList<E> &list)
{
    if (this != &list)
    {
        Node<E> *current;
        current = head;
        while (current)
        {
            current = current->next;
            delete head;
            head = current;
        }

        head = new Node<E>(list.head->data);

        Node<E> *copy = list.head->next;
        Node<E> *old = new Node<E>(list.head->next->data);

        head->next = old;

        while (copy != list.tail)
        {
            old->next = new Node<E>(copy->next->data);

            copy = copy->next;
            old = old->next;
        }
    }

    return *this;
}