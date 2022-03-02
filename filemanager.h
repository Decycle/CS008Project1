#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <fstream>
#include <iostream>
#include <sstream>
#include "linkedlist.h"
#include "date.h"
#include "purchase.h"
#include "member.h"
/****************************************************************
* FileManager Class
*   This class will help keep track of the text files for the purpose of read
*   and writing.
***************************************************************/
class FileManager
{
private:

public:
  static LinkedList<Purchase> readDayfile(string fileName);
//   static LinkedList<Member> readMemberFile(string fileName);
//   static void saveFiles();
};

#endif // FILEMANAGER_H
