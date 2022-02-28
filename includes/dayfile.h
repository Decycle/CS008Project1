#ifndef DAYFILE_H
#define DAYFILE_H
#include "date.h"

class Dayfile
{
    Date _day;
    std::string _filename;
public:
    Dayfile();
    std::string getFile();
    void setfile(std::string filename);
    Date getDay();
    void setDay(Date day);
};

#endif // DAYFILE_H
