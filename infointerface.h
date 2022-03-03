#ifndef INFOINTERFACE_H
#define INFOINTERFACE_H
#include <iostream>
#include "linkedlist.h"
#include "member.h"
#include "purchase.h"
#include "filemanager.h"
#include <fstream>
#include <string>

using namespace std;

const double REBATEPERCENT = 0.05;                  //CONSTANT- rebate precentage
const double BASICYEARLY = 60;                      //CONSTANT- basic member yearly rate
const double PREFERREDYEARLY = 75;
const string FILETYPE = ".txt";                  //CONSTANT-file type
const string FILEDIR = "/Users/ziminyang/Documents/c++/class3/Project1/";    //CONSTANT-auto directory path
const int MAXCHAR = 50;
/****************************************************************
* InfoInterface Class
*   This class will represent the current and updated information of the
*   warehouse. It
*   keeps track of all of the members as well as every purchase
*   made. It reads in all .txt files for both objects to be read
*   in and for easy access to write to each of these files.
***************************************************************/

class InfoInterface
{
public:
    InfoInterface();
    void readDayFile(string filename);
    void readMemberFile(string filename);
    string getDayReport(Date Date);
    string getYearReport(unsigned year);
    string getMemberNumberReport(string memberID);
    string getMemberNameReport(string memberName);
    string getTotalMemberReport();
    string getItemReport(string itemName);
    string getItemTotalReport();
    string getRebateReport();
    string getAmountPerYearPaidReport();
    string membershipMonthExpire(unsigned month);
    void addMember(string name, string id, string type, Date date);
    void addMember(string name, string id, string type, unsigned month, unsigned day, unsigned year);
    void deleteMember(string id);
    void createPurchase(Date purchaseDate, string memberID, string productName, double price, int quantity);
    void deletePurchase(string memberID);
    bool shouldSwitchPreferred(string memberID);
    void SwitchPreferred(string memberID);
    bool shouldSwitchBasic(string memberID);
    void SwitchBasic(string memberID);
    void updateInfo();
    bool ifPurchaseDayExists(Date day);
    void deleteMemberPurchases(string memberID);
    bool alphabetOrder(string a, string b);
    string findMemberID(string memberName);
    void writeMember();
    void writePurchase(string purFile, int purFileIndex);


    string getFullReport();
private:
    LinkedList<Member> memberList;
    LinkedList<Purchase> purchaseList;
};

#endif // INFOINTERFACE_H
