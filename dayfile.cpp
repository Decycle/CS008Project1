#include "dayfile.h"

Dayfile::Dayfile()
{
    _day = Date();
    _filename = "";
}

Dayfile::Dayfile(Date day, string filename)
{
    _day = day;
    _filename = filename;
}

string Dayfile::getFile()
{
    return _filename;
}

void Dayfile::setfile(string filename)
{
    _filename = filename;
}

Date Dayfile::getDate()
{
    return _day;
}

void Dayfile::setDate(Date day)
{
    _day = day;
}

void Dayfile::setDate(string day)
{
    day >> _day;
}
