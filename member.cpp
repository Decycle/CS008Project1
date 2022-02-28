#include "member.h"

Member::Member() {
    member_name= "";
    member_id = "";
    member_type = "";
    member_expired_date = Date();
}

Member::Member(string name, string id, string type, Date date):member_name(name),member_id(id),member_type(type), member_expired_date(date) {

}


void Member::set_info(string name, string id, string type, std::string date){
    setMemberName(name);
    setMemberId(id);
    setMemberType(type);
    setMemberExpiredDate(date);
}



void Member::print(){
    cout <<"Shopper: [" << this->getMemberName() << "], ["<< this->getMemberId()<<"], ["
         << this->getMemberType()<<"], ["<< this->getMemberExpiredDate()<< "]\n";
}


string Member::getMemberType(){
    return member_type;
}

void Member::setMemberType(const string memberType) {
    member_type = memberType;
}
string Member::getMemberName(){
    return member_name;
}

void Member::setMemberName(const string memberName) {
    member_name = memberName;
}

string Member::getMemberId(){
    return member_id;
}

void Member::setMemberId(const string memberId) {
    member_id = memberId;
}

Date Member::getMemberExpiredDate(){
    return member_expired_date;
}

void Member::setMemberExpiredDate(std::string memberExpiredDate) {
    memberExpiredDate>>member_expired_date;
}
