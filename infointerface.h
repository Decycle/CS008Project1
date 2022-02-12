#ifndef INFOINTERFACE_H
#define INFOINTERFACE_H
#include <iostream>
#include "list.h"
#include "member.h"
#include "purchase.h"
#include "filemanager.h"

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
    //1, A sales report for any given day.
    std::string getDayReport(Date day);
    //2, A yearly sales report.
    std::string getYearReport(unsigned year);
    //3 A user should be able to enter a membership number or name and get
    //a list of the total purchases per that member.
    std::string getMemberNumberReport(std::string memberID);
    std::string getMemberNameReport(std::string memberName);
    //4,sorted by member ID
    //include a grand total of the purchases.
    std::string getTotalMemberReport();
    //5,enter an item name and get the quantity
    //of that item sold as well as the total sales price.
    std::string getItemReport(std::string itemName);
    //6 quantity of each item sold sorted by item name
    std::string getItemTotalReport(std::string itemName);
    //7 prints out the rebate of all the preferred members sorted by
    //membership number
    std::string getRebateReport();
    /*8
     * A report showing the amount per year paid by each member for the
     *  membership dues sorted by member type (basic/preferred and then by
     *   member name.)
     * */
    std::string getAmountPerYearPaidReport();
    /*9
     * A user should be able to enter a month and get a list of all members
     *  whose memberships expire that month as well as their dues amount.
     * */
    std::string membershipMonthExpire(std::string month);
    //10 adding and deleting members
    void addMember(member add);
    void deleteMember(member del);

    //11.1
    /*Determine if any basic customer should convert their membership to
     * preferred status.*/
    bool shouldSwitchPreferred(std::string memberID);

    //11.2 actually do 11.1
    void SwitchPreferred(std::string memberID);
    //12.1
    /*
     * Determine if any preferred customer should convert their membership to basic status.
     */
    bool shouldSwitchBasic(std::string memberID);

    //12.2actually do 12.2
    bool SwitchBasic(std::string memberID);

    //13 save changes made, uses FileManager for #9-12 to make changes onto
    // the respective .txt files
    void updateInfo();
private:
    LinkedList<member> memberList;
    LinkedList<Purchase> purchaseList;
    //textfile manager for both purchases and members

    //has linked list of purchase files (by day) and 1 member file
    FileManager files;
};

#endif // INFOINTERFACE_H
