#include <iostream>
#include <exception>

using namespace std;

#ifndef LISTEMPTY_H
#define LISTEMPTY_H

/**************************************************************************
 * ListEmpty
 *  This is a class for the exception that the class is empty.
 *************************************************************************/
class ListEmpty
{
private:
    string message;

public:
    inline ListEmpty(const string message);
    /******************************************************************
     * ~LinkedList();
     *      Constructor; This function should initialize members
     *-----------------------------------------------------------------
     *      Parameters: none
     *-----------------------------------------------------------------
     *      Return: none
     *****************************************************************/

    inline ~ListEmpty();
    /******************************************************************
     * ~ListEmpty();
     *      Destructor; This function should deallocate all remaining
     *      dynamically allocated memory
     *-----------------------------------------------------------------
     *      Parameters: none
     *-----------------------------------------------------------------
     *      Return: none
     *****************************************************************/
};

/**************************************************************************
 *
 * Method ListEmpty: Class ListEmpty
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
 *      This function returns an iterator at the beginning of the linked
 * list.
 *      prints a message if list empty
 *************************************************************************/
ListEmpty::ListEmpty(const string message // PROC-status message
)
{
    // OUT- print status message
    cout << message;
}

/**************************************************************************
 *
 * Method ListEmpty: Class ListEmpty
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
 *      This function clears the memory
 *
 *      Returns nothing
 *************************************************************************/
ListEmpty::~ListEmpty()
{
    // PROC-empty message
    message = "";
}

#endif // LISTEMPTY_H
