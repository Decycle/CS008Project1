#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <fstream>
#include <iostream>
#include "list.h"
/****************************************************************
* FileManager Class
*   This class will manage the text files for the purpose of read
*   and writing. It can edit the purchases per member and
***************************************************************/
class FileManager
{
private:
    //names of purchase files
    LinkedList<std::string> purchaseFiles;
    //names of member files
    std::string memberfile;


public:
  FileManager();
};

#endif // FILEMANAGER_H
