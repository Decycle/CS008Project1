#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

#include "linkedlist.cpp"
#include "date.h"

class Member
{
public:
    Member();
    Member(string id, Date date, string name="",  string type="Basic");
    void set_info(string id, Date date, string name="",  string type="Basic");
    void setMemberType(string type);
    void print();
    string getMemberName();
    string getMemberId();
    Date getMemberExpiredDate();
    string getMemberType();

private:
    string member_name;
    string member_id;
    string member_type;         //basic / preferred
    Date member_expired_date;
};

#endif // MEMBER_H
