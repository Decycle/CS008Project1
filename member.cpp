#include "member.h"

Member::Member(string id, string name, string type, Date* date)
{
    set_info(id, name, type, date);
}

void Member::set_info(string id, string name, string type, Date* date)
{
    this->member_name = name;
    this->member_id = id;
    this->member_type = type;
    this->member_expired_date = date;
}

void Member::print(){
    cout <<"Shopper: [" << this->getMemberName() << "], ["<< this->getMemberId()<<"], ["
         << this->getMemberType()<<"], ["<< this->getMemberExpiredDate()<< "]\n";
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

Date* Member::getMemberExpiredDate(){
    return member_expired_date;
}
