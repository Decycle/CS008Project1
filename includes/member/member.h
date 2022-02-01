
#ifndef PROJ_WAREHOUSE_MEMBER_H
#define PROJ_WAREHOUSE_MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
class member {


public:
    member();
    member(string name, string id);

    vector<member> member_list;

    void setMemberList(member ech_member);
    const vector<member> &getMemberList() const;
    const string &getMemberName() const;
    void setMemberName(const string &memberName);
    const string &getMemberId() const;
    void setMemberId(const string &memberId);
    const string &getMemberExpiredDate() const;
    void setMemberExpiredDate(const string &memberExpiredDate);
    const string &getMemberIssueDate() const;
    void setMemberIssueDate(const string &memberIssueDate);
    int getYearlyRebate() const;
    void setYearlyRebate(int yearlyRebate);
    void setMemberType(int memberPayment);
    const string &getMemberType() const;
    void setMemberType(const string &memberType);


    const int BASIC_MEMBER_ANNUAL = 60;
    const int PREFE_MEMBER_ANNUAL = 75;
private:
    string member_name;
    string member_id;
    string member_type;         //basic / preferred
    string member_expired_date;
    string member_issue_date;
    double yearly_rebate;      //5% FOR PREFERR MEMBER

};


#endif //PROJ_WAREHOUSE_MEMBER_H
