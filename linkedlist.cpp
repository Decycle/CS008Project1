#include "linkedlist.h"

/**************************************************************************
 *
 * Method Iterator(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * Constructor;
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Initialize the iterator.  Basically just need to set the pointer to NULL
 *
 *      No return value
 *************************************************************************/
template <class E>
Iterator<E>::Iterator()
{
    //PROC-initialize iterator
    current = nullptr;
}



/**************************************************************************
 *
 * Method Iterator(Node<E> *ptr): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Initialize the iterator with the parameter passed in.  Need to set the
 *      pointer equal to whatever pointer is passed in.
 *
 *      There is no return value
 *************************************************************************/
template <class E>
Iterator<E>::Iterator(Node<E> *ptr)          // Node<E>
{
    //PROC-set iterator to pointer
    current = ptr;
}
/**************************************************************************
 *
 * Method operator*(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - return current->data;
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function overloads the dereferencing operator*.  It should return
 *      the info contained in the node.
 *
 *      Returns info contained in the node
 *************************************************************************/
template <class E>
E Iterator<E>::operator*()
{
    //PROC-get value of iterator node
    return current->data;
}
/**************************************************************************
 *
 * Method operator++(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns current
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function overloads the pre-increment operator++.
 *
 *      It should return an iterator that is pointing to the next node.
 *************************************************************************/
template <class E>
Iterator<E> Iterator<E>::operator++()
{
    //PROC-gets next node/iterator
    return current = current->next;
}
/**************************************************************************
 *
 * Method operator--(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns
 * -------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function overloads the pre-increment operator++.
 *
 *      It should return an iterator that is pointing to the previous node.
 *************************************************************************/
template <class E>
Iterator<E> Iterator<E>::operator--()
{
    //PROC-goes to previous iterator
    return current = current->prev;
}
/**************************************************************************
 *
 * Method operator==(const Iterator& right): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns true or false
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      right           // Iterator
 *
 * POST-CONDITIONS
 *      This function overloads the equality operator.
 *
 *      Should return true if this iterator is equal to the iterator specified
 *      by right, otherwise it returns false.
 *************************************************************************/
template <class E>
bool Iterator<E>::operator==(const Iterator& right  //PROC-right iterator
                             ) const
{
    //PROC-returns bool for node == node
    return current == right.current;
}
/**************************************************************************
 *
 * Method operator!=(const Iterator& right): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives Iterator right
 * - returns true or false
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      right           // Iterator
 *
 * POST-CONDITIONS
 *      This function overloads the not equal to operator.
 *
 *      Should return true if this iterator is not equal to the iterator
 *      specified by right, otherwise it returns false.
 *************************************************************************/
template <class E>
bool Iterator<E>::operator!=(const Iterator& right) const // iterator
{
    //PROC-returns bool for node != node
    return current != right.current;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Initialize an empty LinkedList.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
LinkedList<E>::LinkedList(): head(nullptr)  //PROC- initialize blank head
                           , tail(nullptr)  //PROC- initialize blank tail
{
//    std::cout << "using Sean L's Linked list\n";
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives LinkedList source
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      source          // LinkedList
 *
 * POST-CONDITIONS
 *      Called when a LinkedList is declared and initialized using an
 *      existing LinkedList.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
LinkedList<E>::LinkedList(const LinkedList<E>& source //PROC-source to copy
                          ):head(nullptr), tail(nullptr)
{
    //PROC- if list isnt empty
    if (head == nullptr)
    {
        //PROC- set head and tail
        head = new Node<E>(*source.head);
        tail = new Node<E>(*source.tail);
    }
    else
    {
        //PROC- go to next node until tail
        tail->next = new Node<E>(*source.head);
        //PROC- set as tail
        tail = new Node<E>(*source.tail);
    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function should deallocate all remaining dynamically allocated
 *      memory (all remaining Nodes).
 *
 *      There is no return value
 *************************************************************************/
template<class E>
LinkedList<E>::~LinkedList()
{
    //PROC-clear contents
    clear();
    head=nullptr;
    tail=nullptr;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function should deallocate all remaining dynamically allocated
 *      memory (all remaining Nodes).
 *
 *      There is no return value
 *************************************************************************/
template<class E>
E& LinkedList<E>::operator[](const unsigned i){
    Node<E> *walker = head;
    for(unsigned j = 0; j < i; j++){
        walker=walker->next;
    }
    return walker->data;
}

template<class E>
void LinkedList<E>::operator+=(const LinkedList<E> &other)
{
    Node<E> *current = other.head;
    while(current != nullptr){
        push_back(current->data);
        current = current->next;
    }
}

/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives LinkedList source
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      source          // LinkedList
 *
 * POST-CONDITIONS
 *      Called when using the assignment operator to set one LinkedList equal
 *      to another.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
LinkedList<E>& LinkedList<E>::operator=(const LinkedList<E>& source // List
                                        )
{

    Node<E> *head2;        //PROC-temp head node
    Node<E> *tail2;        //PROC-temp tail node
    //PROC-set node
    head2 = source.head;

    //PROC-if list is equal
    if(this == &source)
        //OUT-set self
        return *this;

    //PROC-if both lists are not empty
    if(head != nullptr && head2 != nullptr)
        clear();

    //PROC-if list is not blank
    if(head2 != nullptr)
    {
        //PROC-set head value
        head = new Node<E>(head2->data);
    }

    //PROC-set head value
    tail2 = head;

    //PROC-until head node doesnt reach end
    while(head2 != nullptr)
    {
        //PROC-go to next node
        head2 = head2->next;
        //PROC-if not at end
        if(head2 != nullptr)
        {
            //PROC-set next node
            tail2->next = new Node<E>(head2->data);
            //PROC-go to next node
            tail2 = tail2->next;
        }
    }
    //PROC-set tail value
    tail = tail2;
    //OUT-set self
    return *this;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Displays the contents of the LinkedList.
 *
 *      There is no return value
 **************************************************************************/
template<class E>
std::string LinkedList<E>::display() const
{
    stringstream out;
    Node<E>* temp;                              //PROC- New Node
    temp = head;                                //PROC- set to head
    //PROC- until not at end of list
    while (temp != nullptr)
    {
        //PROC- print current node
        out << temp->data;
        //PROC- go to next node
        temp = temp->next;
        //PROC- until not at end
        if (temp != nullptr)
        {
            //PROC- space the printed nodes as passed
            out << ' ';
        }
    }
    return out.str();
}
/**************************************************************************
 *
 * Method operator*(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - return current->data;
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function overloads the dereferencing operator*.  It should return
 *      the info contained in the node.
 *
 *      Returns info contained in the node
 *************************************************************************/

template<class E>
string LinkedList<E>::partial_display(unsigned start, unsigned end) const
{

    unsigned count = 1; //start min is 1

    Node<E>* temp = head;

    string tempo;
    stringstream send;
    send.clear();
    //PROC- New Node                            //PROC- set to head
    //PROC- until not at end of list
    for (int i=0;i<length();i++)
    {
        if(count>=start && count<=end)
        {
            //PROC- print current node
            send << (temp->data);
            send << "";
        }
        //PROC- go to next node
        temp = temp->next;
        //PROC- until not at cout
        //--------------------
        count++;
    }
    return (send.str());
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives value
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      value     // value passed in that will be in new node
 *
 * POST-CONDITIONS
 *      This function inserts a data value (within a new node) at the front end
 *      of the list.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
void LinkedList<E>::push_front(const E& value       //INPUT- to push front
                               )

{
    //PROC-if empty
    if (head == nullptr)
    {
        //PROC-sets front node
        head = new Node<E>(value);
    }
    else//if not empty
    {
        Node<E>* temp;                              //PROC- New Node
        //PROC-set temp node
        temp = new Node<E>(value);
        //PROC-go to next node
        temp->next = head;
        //PROC-set head to temp until at end of list
        head = temp;
    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives value
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      value     // value passed in that will be in new node
 *
 * POST-CONDITIONS
 *      This function inserts a data value (within a new node) at the back end
 *      of the list.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
void LinkedList<E>::push_back(const E& value        // IN- value
                              )
{
    Node<E>* walker = head;
    //PROC-if empty
    if (head == nullptr)
    {
        //PROC-sets front node
        head = new Node<E>(value);
    }
    else//if not empty
    {
        Node<E>* temp;                              //PROC- New Node
        //PROC-set temp node
        temp = new Node<E>(value);
        //while next node is not last
        while(walker->next != nullptr)
            walker=walker->next;

        walker->next = temp;
    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function removes the value (actually removes the node that contains
 *      the value) at the front end of the list. Exception handling if the list
 *      is empty.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
void LinkedList<E>::pop_front()//PROC- if list is empty
{
    //PROC-exception if list is empty
    if (isEmpty())
        //PROC- throw
        throw ListEmpty("List is Empty\n");
    else if(length() == 1)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else if (length() > 1)
    {
        Node<E>* temp=head;
        head=head->next;
        delete temp;

    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function removes the value (actually removes the node that contains
 *      the value) at the front end of the list. Exception handling if the list
 *      is empty.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
void LinkedList<E>::pop_back() //PROC- if list is empty
{
    //PROC-exception if list is empty
    if (isEmpty())
        //PROC- throw
        throw ListEmpty("List is Empty\n");
    else if(length() == 1)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else if (length() > 1)
    {
        Node<E>* beforeWalker;
        Node<E>* walker=head;
        while(walker->next != nullptr)
        {
            beforeWalker = walker;
            walker = walker->next;
        }
        delete walker;
        beforeWalker->next = nullptr;

    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Returns the element at the head of the LinkedList.  Exception handling
 *      if the list is empty.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
const E& LinkedList<E>::front() const //PROC- if list empty
{
    //PROC- if empty
    if (isEmpty())
        //PROC- go through exception
        throw ListEmpty("List is Empty\n");
    else
        //PROC- return front node value
        return head->data;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      Returns the element at the tail of the LinkedList.  Exception handling
 *      if the list is empty.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
const E& LinkedList<E>::back() const //PROC- if list empty
{
    //PROC- if empty
    if (isEmpty())
        //PROC- go through exception
        throw ListEmpty("List is Empty\n");
    else
        //PROC- return back node value
        return tail->data;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns nothing
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function makes the List Empty by deallocating all of the nodes in
 *      the List.
 *
 *      There is no return value
 *************************************************************************/
template<class E>
void LinkedList<E>::clear()
{
    while(!isEmpty())
    {
        pop_front();
    }
}

//inserts after
template<class E>
void LinkedList<E>::insert_nth(E& data, int pos)
{
    Node<E>* temp;
    Node<E>* walker;
    Node<E>* walkerAfter;
    if (pos == 0)  //if first insert
        push_back(data);
    else if ((length()-1) == pos)  //if last insert
        push_back(data);
    else{     //if somewhere
        walker= head;
        temp = new Node<E>(data);
        for (int i = 0; i < pos ; i++)
        {
           walkerAfter = walker;
           walker = walker->next;
        }
        walkerAfter = walker->next;
        walker->next = temp;
        temp->next = walkerAfter;
    }




//    for (int i = 0; i < position - 2; i++)
//    {
//       temp2 = temp2->next;
//    }

//    temp1->next = temp2->next;
//    temp2->next = temp1;

}

template<class E>
void LinkedList<E>::delete_nth(int pos)
{
    Node<E>* walker = head;
    Node<E>* walkerBefore;
    Node<E>* walkerAfter;
    if (pos == 0)  //if first insert
        pop_front();
    else if ((length()-1) == pos)  //if last insert
        pop_back();
    else{     //if somewhere between
        for (int i = 0; i < pos ; i++)
        {
           walkerBefore = walker;
           walker = walker->next;
        }
        walkerAfter = walker->next;
        delete walker;
        walkerBefore->next = walkerAfter;
    }
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns return Iterator<E>(head);
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function returns an iterator at the beginning of the linked list.
 *
 *      Returns an iterator pointing to head.
 *************************************************************************/
template<class E>
Iterator<E> LinkedList<E>::begin()
{
    //PROC-return front of iterator
    return Iterator<E>(LinkedList<E>::front());
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns Iterator<E>(nullptr);
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function returns an iterator one element past the last element of
 *      the linked list.
 *
 *      Returns an iterator pointing to NULL.
 *************************************************************************/
template<class E>
Iterator<E> LinkedList<E>::end()
{
    //PROC-return back of iterator
    return Iterator<E>(LinkedList<E>::back());
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns 0 or 1 + length()
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function determines the length of the list
 *
 *      Returns length of linked list
 *************************************************************************/
template<typename E>
int LinkedList<E>::length() const
{
    int count = 0;
    Node<E> *walker = head;
    //if empty
    if (walker == nullptr)
        return 0;
    //if 1 node
    if (walker != nullptr && walker->next == nullptr)
        return 1;
    //PROC-while not at last element and not empty
    while (walker != nullptr)
    {
        walker = walker->next;
        count++;
    }
    return count;
}
/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - returns 0 or current->data + sum()
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function recursively determines the sum of all of the elements in
 *      the list.
 *
 *      Returns sum of the linked list
 *************************************************************************/
template<class E>
int LinkedList<E>::sum() const
{
    Node<E>* temp;                            //PR0C-Temp Node
    temp = head;                              //PROC-Set temp

    //PROC-if list is empty
    if (head == nullptr)
        return 0;
    else
    {
        //PROC-while not at end of list
        while(temp != nullptr)
        {
            //PROC-go to next node
            temp = temp->next;
            //PROC-add and recursively add next node
            return temp->data + sum();
        }
    }
}

/**************************************************************************
 *
 * Method LinkedList<E>: Class LinkedList<E>
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - return head == nullptr;
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function sees whether this list is empty.
 *
 *      Returns true if head = nullptr
 *************************************************************************/
template<class E>
bool LinkedList<E>::isEmpty() const
{
    //PROC-if empty
    return (head == nullptr && tail == nullptr);
}
/**************************************************************************
 *
 * Method operator*(): Class Iterator
 *
 * ------------------------------------------------------------------------
 * This method receives nothing
 * - return current->data;
 * ------------------------------------------------------------------------
 * PRE-CONDITIONS
 *      The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *      This function overloads the dereferencing operator*.  It should return
 *      the info contained in the node.
 *
 *      Returns info contained in the node
 *************************************************************************/
template<class E>
Node<E>& LinkedList<E>::GetN(unsigned index)
{
    unsigned count=0;
    Node<E>* temp = head;
    while (temp!=nullptr)
    {
        if(count == index)
            return (temp->data);
        count++;
        temp = temp->next;
    }
}
