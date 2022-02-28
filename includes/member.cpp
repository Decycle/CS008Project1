#include "member.h"

#include <utility>

Member::Member() {
    member_name= "";
    member_id = "";
    member_type = "";
    member_expired_date = Date();
}

Member::Member(std::string name, string id, string type, Date date):member_name(std::move(name)),member_id(std::move(id)),member_type(std::move(type)), member_expired_date(std::move(date)) {

}
Member::Member(string name, string id, string type, string date){
    set_info(std::move(name),std::move(id), std::move(type), std::move(date));
}

void Member::set_info(string name, string id, string type, std::string date){
    setMemberName(std::move(name));
    setMemberId(std::move(id));
    setMemberType(std::move(type));
    setMemberExpiredDate(std::move(date));
}

void Member::upgradeMember(){
    if(this->member_type=="Basic")
        this->member_type = "Preferred";
    else
        this->member_type = "Basic";
}

void Member::downgradeMember(){
    if(this->member_type=="Preferred")
        this->member_type = "Basic";
    else
        this->member_type = "Basic";
}

void Member::print(){
    cout <<"Shopper: [" << this->getMemberName() << "], ["<< this->getMemberId()<<"], ["
         << this->getMemberType()<<"], ["<< this->getMemberExpiredDate()<< "]\n";
}


string Member::getMemberType(){
    return member_type;
}

void Member::setMemberType(string memberType) {
    member_type = std::move(memberType);
}
string Member::getMemberName(){
    return member_name;
}

void Member::setMemberName(string memberName) {
    member_name = std::move(memberName);
}

string Member::getMemberId(){
    return member_id;
}

void Member::setMemberId(string memberId) {
    member_id = std::move(memberId);
}

Date Member::getMemberExpiredDate(){
    return member_expired_date;
}

void Member::setMemberExpiredDate(std::string memberExpiredDate) {
    memberExpiredDate>>member_expired_date;
}
