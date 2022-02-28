#ifndef DAYFILE_H
#define DAYFILE_H
#include "date.h"

class Dayfile
{
    Date _day;
    std::string _filename;
public:
    Dayfile();
    Dayfile(Date day, std::string filename);
    std::string getFile();
    void setfile(std::string filename);
    Date getDate();
    void setDate(Date day);
    void setDate(std::string day);
};

#endif // DAYFILE_H
