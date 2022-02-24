
#include "member.h"

member::member()
{
    //    member_name="";
    //    member_id ="";
    //    member_type = "";
    //    member_expired_date = "";
}

member::member(string name, string id, string type, string date) : member_name(name), member_id(id), member_type(type), member_expired_date(date)
{
}

void member::setMemberType(int memberPayment)
{
    if (memberPayment == BASIC_MEMBER_ANNUAL)
    {
        member_type = "BASIC";
        yearly_rebate = 0;

        vector<tm *> date = getCurrentDate();
        string date_string = "";
        for (int i = 0; i < date.size(); i++)
        {
            date_string += to_string(reinterpret_cast<int>(date.at(i)));
        }
        setMemberIssueDate(date_string);

        // set expired date, one year period
        // setMemberExpiredDate(get)
    }
    else if (memberPayment == PREFE_MEMBER_ANNUAL)
    {
        member_type = "PREFERRED";
        yearly_rebate = 0.05;
    }
    else
    {
        cout << "Invalid member payment\n";
    }
}

void member::read_file(string file_name)
{

    ifstream in(file_name.c_str());
    if (in.fail())
    {
        cout << "Open file failed.\n";
        exit(1);
    }
    string name, id, type, date;

    member m;

    do
    {
        // in >> name;
        getline(in, name);
        getline(in, id);
        getline(in, type);
        getline(in, date);

        m.set_info(name, id, type, date);
        // member_list.push(m);
        // repo.add_member(m);
        m.print();

    } while (!in.eof());

    in.close();
}

void member::set_info(string name, string id, string type, string date)
{
    setMemberName(name);
    setMemberId(id);
    setMemberType(type);
    setMemberExpiredDate(date);
}
// const LinkedList<member> &member::getMemberList() const {
//     return member_list;
// }

void member::print()
{

    cout << "Shopper: [" << this->getMemberName() << "], [" << this->getMemberId() << "], ["
         << this->getMemberType() << "], [" << this->getMemberExpiredDate() << "]\n";
}
// void member::print_list() {
//
//     for(int i=0; i< member_list.listSize(); i++){
//         cout << member_list;
//         cout << __LINE__<< endl;
//     }
//     cout << __LINE__<< endl;
// }

vector<tm *> member::getCurrentDate()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    vector<tm *> temp;
    temp.push_back(reinterpret_cast<tm *const>(timePtr->tm_year + 1900));
    temp.push_back(reinterpret_cast<tm *const>(timePtr->tm_mon + 1));
    temp.push_back(reinterpret_cast<tm *const>(timePtr->tm_mday));

    //    string year = to_string(timePtr->tm_year +1900);
    //    string month = to_string(timePtr->tm_mon +1);
    //    string day = to_string(timePtr->tm_mday);

    return temp;
}

void member::setPurchaseHistory(string item)
{
}

vector<string> member::getPurchaseHistory()
{
}
const string &member::getMemberType() const
{
    return member_type;
}

void member::setMemberType(const string &memberType)
{
    member_type = memberType;
}
const string &member::getMemberName() const
{
    return member_name;
}

void member::setMemberName(const string &memberName)
{
    member_name = memberName;
}

const string &member::getMemberId() const
{
    return member_id;
}

void member::setMemberId(const string &memberId)
{
    member_id = memberId;
}

const string &member::getMemberExpiredDate() const
{
    return member_expired_date;
}

void member::setMemberExpiredDate(const string &memberExpiredDate)
{
    member_expired_date = memberExpiredDate;
}

const string &member::getMemberIssueDate() const
{
    return member_issue_date;
}

void member::setMemberIssueDate(const string &memberIssueDate)
{
    member_issue_date = memberIssueDate;
}

double member::getYearlyRebate() const
{
    return yearly_rebate;
}

void member::setYearlyRebate(int total_amount)
{
    // if()
    yearly_rebate = total_amount * 0.05;
}