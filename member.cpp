
#include "member.h"

member::member() {
}

member::member(string name, string id):member_name(name),member_id(id) {

}
const string &member::getMemberName() const {
    return member_name;
}

void member::setMemberName(const string &memberName) {
    member_name = memberName;
}

const string &member::getMemberId() const {
    return member_id;
}

void member::setMemberId(const string &memberId) {
    member_id = memberId;
}

const string &member::getMemberExpiredDate() const {
    return member_expired_date;
}

void member::setMemberExpiredDate(const string &memberExpiredDate) {
    member_expired_date = memberExpiredDate;
}

const string &member::getMemberIssueDate() const {
    return member_issue_date;
}

void member::setMemberIssueDate(const string &memberIssueDate) {
    member_issue_date = memberIssueDate;
}

int member::getYearlyRebate() const {
    return yearly_rebate;
}

void member::setYearlyRebate(int yearlyRebate) {
    yearly_rebate = yearlyRebate;
}


void member::setMemberType(int memberPayment) {
    if(memberPayment == BASIC_MEMBER_ANNUAL){
        member_type = "BASIC";
        yearly_rebate =0;
        //setMemberIssueDate()
    }
    else if(memberPayment == PREFE_MEMBER_ANNUAL){
        member_type = "PREFERRED";
        yearly_rebate = 0.05;
    }
    else{
        cout << "Invalid member payment\n";
    }
}

const vector<member> &member::getMemberList() const {
    return member_list;
}

void member::setMemberList(member each_member) {
    member_list.push_back(each_member);
}

const string &member::getMemberType() const {
    return member_type;
}

void member::setMemberType(const string &memberType) {
    member_type = memberType;
}
