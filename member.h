#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>

#include "linkedlist.h"
#include "date.h"

class Member {


public:
    Member();
    Member(string name, string id, string type, Date date);

    void print();
    void set_info(string name, string id, string type, std::string date);


    string getMemberName();                            //getter of Member name
    void setMemberName(const string memberName);                   //set Member name

    string getMemberId();                              //getter of Member id
    void setMemberId(const string memberId);                       //set Member id

    Date getMemberExpiredDate();                     //getter of Member expired date
    void setMemberExpiredDate(std::string memberExpiredDate);     //set Member expired date

    string getMemberType();
    void setMemberType(const string memberType);

private:
    string member_name;
    string member_id;
    string member_type;         //basic / preferred
    Date member_expired_date;
};

#endif // MEMBER_H
