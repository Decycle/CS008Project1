
#ifndef PROJ_WAREHOUSE_MEMBER_H
#define PROJ_WAREHOUSE_MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <map>

using namespace std;
class member
{

public:
    const int BASIC_MEMBER_ANNUAL = 60;
    const int PREFE_MEMBER_ANNUAL = 75;

    // report repo;
    member();
    member(string name, string id, string type, string date);

    // LinkedList<member> member_list;
    vector<tm *> getCurrentDate();
    void setPurchaseHistory(string item);
    vector<string> getPurchaseHistory();

    void print();
    // void print_list();
    void read_file(string file_name);
    void set_info(string name, string id, string type, string date);
    // void add_member(member member1);

    // const LinkedList<member> &getMemberList() const;                    //getter for list of member
    const string &getMemberName() const;                        // getter of member name
    void setMemberName(const string &memberName);               // set member name
    const string &getMemberId() const;                          // getter of member id
    void setMemberId(const string &memberId);                   // set member id
    const string &getMemberExpiredDate() const;                 // getter of member expired date
    void setMemberExpiredDate(const string &memberExpiredDate); // set member expired date
    const string &getMemberIssueDate() const;                   // getter of member issue date
    void setMemberIssueDate(const string &memberIssueDate);     // set member issue date
    double getYearlyRebate() const;                             // getter of member yearly rebate
    void setYearlyRebate(int total_amount);
    void setMemberType(int memberPayment);
    const string &getMemberType() const;
    void setMemberType(const string &memberType);

private:
    string member_name;
    string member_id;
    string member_type; // basic / preferred
    string member_expired_date;
    string member_issue_date;
    double yearly_rebate; // 5% FOR PREFERR MEMBER
    double member_purchase;
    vector<string> purchase_history;
};

#endif // PROJ_WAREHOUSE_MEMBER_H
