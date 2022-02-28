#include "filemanager.h"

FileManager::FileManager()
{
    memberfile = "warehouse shopppers";
}

string FileManager::getdayfile(Date day)
{
    for(int i = 0; i < purchaseDayFiles.length(); i++)
    {
        if(day ==purchaseDayFiles[i].getDay())
            return purchaseDayFiles[i].getFile();
    }
}

std::string FileManager::getMemberFile()
{
    return memberfile;
}

int FileManager::numberDayFiles()
{
    return purchaseDayFiles.length();
}
