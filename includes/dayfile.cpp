#include "dayfile.h"

Dayfile::Dayfile()
{
    _day = Date();
    _filename = "";
}

string Dayfile::getFile()
{
    return _filename;
}

void Dayfile::setfile(string filename)
{
    _filename = filename;
}

Date Dayfile::getDay()
{
    return _day;
}

void Dayfile::setDay(Date day)
{
    _day = day;
}
