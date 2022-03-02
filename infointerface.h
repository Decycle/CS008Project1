#ifndef INFOINTERFACE_H
#define INFOINTERFACE_H
#include <iostream>
#include "linkedlist.h"
#include "member.h"
#include "purchase.h"
#include "filemanager.h"
#include <fstream>
#include <string>

using namespace std;

const string FILETYPE = ".txt";                  //CONSTANT-file type
const string FILEDIR = "/Users/ziminyang/Documents/c++/class3/Project1/";    //CONSTANT-auto directory path
const int MAXCHAR = 50;
/****************************************************************
* InfoInterface Class
*   This class will represent the current and updated information of the
*   warehouse. It
*   keeps track of all of the members as well as every purchase
*   made. It reads in all .txt files for both objects to be read
*   in and for easy access to write to each of these files.
***************************************************************/

class InfoInterface
{
public:
    InfoInterface();
    void readDayFile(string filename);
    std::string getFullReport();
private:
    LinkedList<Member> memberList;
    LinkedList<Purchase> purchaseList;
};

#endif // INFOINTERFACE_H
