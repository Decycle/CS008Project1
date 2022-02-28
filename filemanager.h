#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <fstream>
#include <iostream>
#include "linkedlist.h"
#include "date.h"
#include "dayfile.h"
#include <sstream>
/****************************************************************
* FileManager Class
*   This class will help keep track of the text files for the purpose of read
*   and writing.
***************************************************************/
class FileManager
{
private:
    std::string memberfile;

public:
  FileManager();

  LinkedList<Dayfile> purchaseDayFiles;

  std::string getdayfile(Date day);
  std::string getMemberFile();
  int numberDayFiles();
};

#endif // FILEMANAGER_H
