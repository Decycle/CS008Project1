#include "member.h"

Member::Member()
{
    set_info("", Date(1, 1, 9999), "", "Basic");
}

Member::Member(string id, Date date, string name,  string type)
{
    set_info(id, date, name, type);
}

void Member::set_info(string id, Date date, string name,  string type)
{
    this->member_name = name;
    this->member_id = id;
    this->member_type = (type == "Preferred" ? "Preferred" : "Basic");
    this->member_expired_date = date;
}

void Member::print(){
    cout <<"Shopper: [" << this->getMemberName() << "], ["<< this->getMemberId()<<"], ["
         << this->getMemberType()<<"], ["<< this->getMemberExpiredDate()<< "]\n";
}

void Member::setMemberType(string type)
{
    this->member_type = (type == "Preferred" ? "Preferred" : "Basic");
}

string Member::getMemberType(){
    return member_type;
}

string Member::getMemberName(){
    return member_name;
}

string Member::getMemberId(){
    return member_id;
}

Date Member::getMemberExpiredDate(){
    return member_expired_date;
}
