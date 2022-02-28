#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <cstring>
#include <string>
#include "linkedlist.h"
#include "date.h"
using namespace std;
class Member {


public:
    const int BASE_MEMBER_ANNUAL = 60;
    const int PREF_MEMBER_ANNUAL = 75;

    Member();
    Member(string name, string id, string type, Date date);
    Member(string name, string id, string type, string date);
    void print();
    void set_info(string name, string id, string type, std::string date);


    string getMemberName();                            //getter of Member name
    void setMemberName(string memberName);                   //set Member name

    string getMemberId();                              //getter of Member id
    void setMemberId(string memberId);                       //set Member id

    Date getMemberExpiredDate();                     //getter of Member expired date
    void setMemberExpiredDate(std::string memberExpiredDate);     //set Member expired date

    string getMemberType();
    void setMemberType(string memberType);

    void upgradeMember();
    void downgradeMember();
private:
    string member_name;
    string member_id;
    string member_type;         //basic / preferred
    Date member_expired_date;
};

#endif // MEMBER_H
