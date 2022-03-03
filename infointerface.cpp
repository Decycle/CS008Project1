#include "infointerface.h"
#include <QDebug>

InfoInterface::InfoInterface()
{

}

void InfoInterface::readDayFile(string filename)
{
    if(purchaseList.length() == 0)
    {
        purchaseList =  FileManager::readDayFile(FILEDIR + filename + FILETYPE);
    }
    else
    {
        purchaseList += FileManager::readDayFile(FILEDIR + filename + FILETYPE);
    }
}

void InfoInterface::readMemberFile(string filename)
{
    memberList = FileManager::readMemberFile(FILEDIR + filename + FILETYPE);
}

/****************************************************************
* string getDayReport(Date day)
* MUTATOR; This method Rreturn  report for any given day.
* --------------------------------------------------------------
* Parameters: Date
* --------------------------------------------------------------
* Return: string
***************************************************************/
std::string InfoInterface::getDayReport(Date day)
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;
    out += "Day report for ";
    out += day.getNumeric();
    out += "\n";
    out += "Date\t\tID\tPrice\tQuant.\tName\n";
    for (int i = 0; i < purchaseList.length(); i++)
    {
        //if match date
        if (day == purchaseList[i].getPurchaseDate()){
            priceStream.str("");
            quantityStream.str("");
            dateStream.str("");
            priceStream.clear();
            quantityStream.clear();
            dateStream.clear();
            dateStream<<purchaseList[i].getPurchaseDate();
            out += dateStream.str() + "\t";
            out += purchaseList[i].getMemberID() + "\t";
            priceStream << purchaseList[i].getProductPrice();
            out += "$"+ priceStream.str();
            out += "\t";
            quantityStream << purchaseList[i].getProductQuantity();
            out += quantityStream.str() + "\t";
            out += purchaseList[i].getProductName();
            out += "\n";
        }
    }
    return out;

}


/****************************************************************
* string getYearReport(unsigned year)
* MUTATOR; This method Rreturn  A yearly sales report.
* --------------------------------------------------------------
* Parameters: unsigned
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getYearReport(unsigned year)
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;
    out += "Year report for ";
    out += year;
    out += "\n";
    out += "Date\t\tID\tPrice\tQuant.\tName\n";
    for (int i = 0; i < purchaseList.length(); i++)
    {
        //if match year
        if (year == purchaseList[i].getPurchaseDate().getYear()){
            priceStream.str("");
            quantityStream.str("");
            dateStream.str("");
            priceStream.clear();
            quantityStream.clear();
            dateStream.clear();
            dateStream<<purchaseList[i].getPurchaseDate();
            out += dateStream.str() + "\t";
            out += purchaseList[i].getMemberID() + "\t";
            priceStream << purchaseList[i].getProductPrice();
            out += "$"+ priceStream.str();
            out += "\t";
            quantityStream << purchaseList[i].getProductQuantity();
            out += quantityStream.str() + "\t";
            out += purchaseList[i].getProductName();
            out += "\n";
        }
    }
    return out;

}


/****************************************************************
* string getMemberNumberReport(string memberID)
* MUTATOR; This method Rreturn  membership report by input id
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getMemberNumberReport(string memberID)
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;
    out += "Member Number report for ";
    out += memberID;
    out += "\n";
    out += "Date\t\tID\tPrice\tQuant.\tName\n";
    for (int i = 0; i < purchaseList.length(); i++)
    {
        //if match year
        if (memberID == purchaseList[i].getMemberID()){
            std::cout <<"member id check:"<< purchaseList[i].getMemberID() << "|";
            priceStream.str("");
            quantityStream.str("");
            dateStream.str("");
            priceStream.clear();
            quantityStream.clear();
            dateStream.clear();
            dateStream<<purchaseList[i].getPurchaseDate();
            out += dateStream.str() + "\t";
            out += purchaseList[i].getMemberID() + "\t";
            priceStream << purchaseList[i].getProductPrice();
            out += "$"+ priceStream.str();
            out += "\t";
            quantityStream << purchaseList[i].getProductQuantity();
            out += quantityStream.str() + "\t";
            out += purchaseList[i].getProductName();
            out += "\n";
        }
    }
    return out;
}


/****************************************************************
* string getMemberNameReport(string memberName)
* MUTATOR; This method Rreturn membership report by input name
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getMemberNameReport(string memberName)
{
    std::string out = "";
    std::string id = findMemberID(memberName);
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;

    out += "Member Name report for ";
    out += memberName;
    out += "\n";
    out += "Date\t\tID\tPrice\tQuant.\tName\n";

    for (int i = 0; i < purchaseList.length(); i++)
    {

        //if match year
        if (id == purchaseList[i].getMemberID()){
            priceStream.str("");
            quantityStream.str("");
            dateStream.str("");
            priceStream.clear();
            quantityStream.clear();
            dateStream.clear();
            dateStream<<purchaseList[i].getPurchaseDate();
            out += dateStream.str() + "\t";
            out += purchaseList[i].getMemberID() + "\t";
            priceStream << purchaseList[i].getProductPrice();
            out += "$"+ priceStream.str();
            out += "\t";
            quantityStream << purchaseList[i].getProductQuantity();
            out += quantityStream.str() + "\t";
            out += purchaseList[i].getProductName();
            out += "\n";
        }
    }
    return out;

}

/****************************************************************
* string getTotalMemberReport()
* MUTATOR; This method Rreturn member report by membership number
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getTotalMemberReport()
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;
    stringstream subTotalStream;
    stringstream grandTotalStream;
    grandTotalStream.str("");
    grandTotalStream.clear();
    subTotalStream.str("");
    subTotalStream.clear();
    double subTotal = 0;
    double grandTotal = 0;
    double eachPurchaseAmount = 0;
    out += "Date\t\tID\tPrice\tQuant.\tName\n";

    std::cout << "Right before copy\n";
    //deep copy
    LinkedList<Purchase> sortedPurchaseList;
    for (int i = 0; i<purchaseList.length(); i++)
    {
        sortedPurchaseList.push_back(purchaseList[i]);
    }
    std::cout << "Right after copy\n";


    Purchase min;                          //PROC-Set current element as minimum

    //PROC-Compare current data to rest of the list
    for (int i = 0; i < sortedPurchaseList.length(); i++)
    {
        //PROC-Set current element as minimum
        min = sortedPurchaseList[i];

        //PROC-check if minimum
        for (int j = 0; j < sortedPurchaseList.length(); j++)
        {
            //PROC-Swap the minimum element & the current element
            if (stoi(sortedPurchaseList[j].getMemberID()) > stoi(min.getMemberID()))
            {
                //PROC-do swap
                min = sortedPurchaseList[j];
                //PROC-do swap
                sortedPurchaseList[j] = sortedPurchaseList[i];
                //PROC-do swap
                sortedPurchaseList[i] = min;
            }
        }
    }
    for (int i = 0; i < sortedPurchaseList.length(); i++)
    {
        priceStream.str("");
        quantityStream.str("");
        dateStream.str("");
        priceStream.clear();
        quantityStream.clear();
        dateStream.clear();
        dateStream << sortedPurchaseList[i].getPurchaseDate();
        out += dateStream.str() + "\t";
        out += sortedPurchaseList[i].getMemberID() + "\t";
        priceStream << sortedPurchaseList[i].getProductPrice();
        out +=  "$"+ priceStream.str();
        out += "\t";
        quantityStream << sortedPurchaseList[i].getProductQuantity();
        out += quantityStream.str() + "\t";
        out += sortedPurchaseList[i].getProductName();
        out += "\n";
        //for the subtotal
        std::cout << "price:" <<sortedPurchaseList[i].getProductPrice()<<"|\n";
        std::cout << "quant:" <<sortedPurchaseList[i].getProductQuantity()<<"|\n";
        eachPurchaseAmount = (sortedPurchaseList[i].getProductPrice() * sortedPurchaseList[i].getProductQuantity());
        subTotal += eachPurchaseAmount;

    }
    //8.75% tax
    grandTotal = subTotal * 1.0875;
    //std::cout << "grand total but not the string:" <<grandTotal<<"|\n";
    subTotalStream << subTotal;
    grandTotalStream << grandTotal;
    out += "\n SubTotal: $";
    out += subTotalStream.str();
    out += "\n Grand Total: $";
    out += grandTotalStream.str();

    sortedPurchaseList.clear();
    //grand total,subtotal and tax
    return out;

}


/****************************************************************
* string getItemReport(string itemName)
* MUTATOR; This method Rreturn  the quantity
* of that item sold as well as the total sales price.
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getItemReport(string itemName)
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;

    out += "Item report for ";
    out += itemName;
    out += "\n";
    out += "Date\t\tID\tPrice\tQuant.\tName\n";

    for (int i = 0; i < purchaseList.length(); i++)
    {

        //if match year
        if (itemName == purchaseList[i].getProductName()){
            priceStream.str("");
            quantityStream.str("");
            dateStream.str("");
            priceStream.clear();
            quantityStream.clear();
            dateStream.clear();
            dateStream<<purchaseList[i].getPurchaseDate();
            out += dateStream.str() + "\t";
            out += purchaseList[i].getMemberID() + "\t";
            priceStream << purchaseList[i].getProductPrice();
            out += "$"+ priceStream.str();
            out += "\t";
            quantityStream << purchaseList[i].getProductQuantity();
            out += quantityStream.str() + "\t";
            out += purchaseList[i].getProductName();
            out += "\n";
        }
    }
    return out;

}


/****************************************************************
* string getItemTotalReport()
* MUTATOR; This method Rreturn quantity of each item sold sorted
by item name SORTED by item name
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getItemTotalReport()
{
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;

    out += "Date\t\tID\tPrice\tQuant.\tName\n";

    std::cout << "Right before copy\n";
    //deep copy
    LinkedList<Purchase> sortedPurchaseList;
    for (int i = 0; i<purchaseList.length(); i++)
    {
        sortedPurchaseList.push_back(purchaseList[i]);
    }
    std::cout << "Right after copy\n";


    Purchase min;                          //PROC-Set current element as minimum

    //PROC-Compare current data to rest of the list
    for (int i = 0; i < sortedPurchaseList.length(); i++)
    {

        //PROC-Set current element as minimum
        min = sortedPurchaseList[i];

        //PROC-check if minimum
        for (int j = 0; j < sortedPurchaseList.length(); j++)
        {
            string minString = min.getProductName();
            string compString = sortedPurchaseList[j].getProductName();
            std::transform(minString.begin(), minString.end(), minString.begin(), ::tolower);
            std::transform(compString.begin(), compString.end(), compString.begin(), ::tolower);

            //PROC-Swap the minimum element & the current element
//            if(compString[0] > minString[0])
//            if (strcmp(compString.c_str(),minString.c_str()))
            if(alphabetOrder(compString,minString))
            {
                //PROC-do swap
                min = sortedPurchaseList[j];
                //PROC-do swap
                sortedPurchaseList[j] = sortedPurchaseList[i];
                //PROC-do swap
                sortedPurchaseList[i] = min;
            }
        }
    }
    for (int i = 0; i < sortedPurchaseList.length(); i++)
    {
        priceStream.str("");
        quantityStream.str("");
        dateStream.str("");
        priceStream.clear();
        quantityStream.clear();
        dateStream.clear();
        dateStream << sortedPurchaseList[i].getPurchaseDate();
        out += dateStream.str() + "\t";
        out += sortedPurchaseList[i].getMemberID() + "\t";
        priceStream << sortedPurchaseList[i].getProductPrice();
        out +=  "$"+ priceStream.str();
        out += "\t";
        quantityStream << sortedPurchaseList[i].getProductQuantity();
        out += quantityStream.str() + "\t";
        out += sortedPurchaseList[i].getProductName();
        out += "\n";
    }
    sortedPurchaseList.clear();
    return out;

}

/****************************************************************
* string getRebateReport()
* MUTATOR; This method Rreturn rebate report sorted by membership number
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getRebateReport()
{
    std::string out = "";
    stringstream dateStream;

    out += "Date\t\tID\tType\t\tName\n";

    std::cout << "Right before copy\n";
    //deep copy
    LinkedList<Member> sortedMemberList;

    for (int i = 0; i<memberList.length(); i++)
    {
        sortedMemberList.push_back(memberList[i]);
    }
    std::cout << "Right after copy\n";


    Member min;                          //PROC-Set current element as minimum

    //PROC-Compare current data to rest of the list
    for (int i = 0; i < sortedMemberList.length(); i++)
    {
        //PROC-Set current element as minimum
        min = sortedMemberList[i];

        //PROC-check if minimum
        for (int j = 0; j < sortedMemberList.length(); j++)
        {
            //PROC-Swap the minimum element & the current element
            if (stoi(sortedMemberList[j].getMemberId()) > stoi(min.getMemberId()))
            {
                //PROC-do swap
                min = sortedMemberList[j];
                //PROC-do swap
                sortedMemberList[j] = sortedMemberList[i];
                //PROC-do swap
                sortedMemberList[i] = min;
            }
        }
    }
    for (int i = 0; i < sortedMemberList.length(); i++)
    {
        if (sortedMemberList[i].getMemberType()== "Preferred")
        {
            dateStream.str("");
            dateStream.clear();

            dateStream << sortedMemberList[i].getMemberExpiredDate();
            out += dateStream.str() + "\t";
            out += sortedMemberList[i].getMemberId() + "\t";
            out += sortedMemberList[i].getMemberType();
            out += "\t";
            out += sortedMemberList[i].getMemberName()+"\n";
        }
    }



    //grand total,subtotal and tax
    sortedMemberList.clear();
    return out;

}


/****************************************************************
* string getAmountPerYearPaidReport()
* MUTATOR; This method Rreturn the amount per year paid by each
member for the membership dues sorted by member type
(basic/preferred and then by member name.)
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::getAmountPerYearPaidReport()
{
    stringstream dateStream;
    std::string out = "";
    LinkedList<Member> sortedBasicList;

    for (int i = 0; i<memberList.length(); i++)
    {
        if (memberList[i].getMemberType() == "Basic")
            sortedBasicList.push_back(memberList[i]);
    }
    LinkedList<Member> sortedPreferredList;

    for (int i = 0; i<memberList.length(); i++)
    {
        if (memberList[i].getMemberType() == "Preferred")
            sortedPreferredList.push_back(memberList[i]);
    }
    out += "Date\t\tID\tType\t\tYearlyDues\tName\n";
    Member min;                          //PROC-Set current element as minimum

        //forbasic
    //PROC-Compare current data to rest of the list
    for (int i = 0; i < sortedBasicList.length(); i++)
    {
        //PROC-Set current element as minimum
        min = sortedBasicList[i];

        //PROC-check if minimum
        for (int j = 0; j < sortedBasicList.length(); j++)
        {

            string minString = min.getMemberName();
            string compString = sortedBasicList[j].getMemberName();
            std::transform(minString.begin(), minString.end(), minString.begin(), ::tolower);
            std::transform(compString.begin(), compString.end(), compString.begin(), ::tolower);

            //PROC-Swap the minimum element & the current element
//            if(compString[0] > minString[0])
//            if (strcmp(compString.c_str(),minString.c_str()))
            if(alphabetOrder(compString,minString))
            {
                //PROC-do swap
                min = sortedBasicList[j];
                //PROC-do swap
                sortedBasicList[j] = sortedBasicList[i];
                //PROC-do swap
                sortedBasicList[i] = min;
            }
        }
    }

    //for preferred
    //PROC-Compare current data to rest of the list
    for (int i = 0; i < sortedPreferredList.length(); i++)
    {
        //PROC-Set current element as minimum
        min = sortedPreferredList[i];

        //PROC-check if minimum
        for (int j = 0; j < sortedPreferredList.length(); j++)
        {

            string minString = min.getMemberName();
            string compString = sortedPreferredList[j].getMemberName();
            std::transform(minString.begin(), minString.end(), minString.begin(), ::tolower);
            std::transform(compString.begin(), compString.end(), compString.begin(), ::tolower);

            //PROC-Swap the minimum element & the current element
//            if(compString[0] > minString[0])
//            if (strcmp(compString.c_str(),minString.c_str()))
            if(alphabetOrder(compString,minString))
            {
                //PROC-do swap
                min = sortedPreferredList[j];
                //PROC-do swap
                sortedPreferredList[j] = sortedPreferredList[i];
                //PROC-do swap
                sortedPreferredList[i] = min;
            }
        }
    }
    for (int i = 0; i < sortedBasicList.length(); i++)
    {
        if (sortedBasicList[i].getMemberType()== "Basic")
        {
            dateStream.str("");
            dateStream.clear();

            dateStream << sortedBasicList[i].getMemberExpiredDate();
            out += dateStream.str() + "\t";
            out += sortedBasicList[i].getMemberId() + "\t";
            out += sortedBasicList[i].getMemberType();
            out += "\t\t";
            out += "$60.00\t\t";
            out += sortedBasicList[i].getMemberName()+"\n";
        }
    }
    for (int i = 0; i < sortedPreferredList.length(); i++)
    {
        if (sortedPreferredList[i].getMemberType()== "Preferred")
        {
            dateStream.str("");
            dateStream.clear();

            dateStream << sortedPreferredList[i].getMemberExpiredDate();
            out += dateStream.str() + "\t";
            out += sortedPreferredList[i].getMemberId() + "\t";
            out += sortedPreferredList[i].getMemberType();
            out += "\t";
            out += "$75.00\t\t";
            out += sortedPreferredList[i].getMemberName()+"\n";
        }
    }

    sortedBasicList.clear();
    sortedPreferredList.clear();
    return out;

}

/****************************************************************
* string membershipMonthExpire(unsigned month)
* MUTATOR; This method Rreturn member that expire member ship
in input month
* --------------------------------------------------------------
* Parameters: unsigned
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::membershipMonthExpire(unsigned month)
{
    stringstream dateStream;
    stringstream dueStream;
    std::string out = "";
    int basicCount = 0;
    int preferredCount = 0;
    double dues = 0;
    out += "Date\t\tID\tType\t\tYearlyDues\tName\n";
    for (int i = 0; i < memberList.length(); i++)
    {
        if (memberList[i].getMemberExpiredDate().getMonth() == month)
        {
            dateStream.str("");
            dateStream.clear();

            dateStream << memberList[i].getMemberExpiredDate();
            out += dateStream.str() + "\t";
            out += memberList[i].getMemberId() + "\t";
            out += memberList[i].getMemberType();
            out += "\t";
            if (memberList[i].getMemberType()== "Basic")
            {
                 out += "\t$60.00\t\t";
                 basicCount++;
            }
            if (memberList[i].getMemberType()== "Preferred")
            {
                out += "$75.00\t\t";
                preferredCount++;
            }
            out += memberList[i].getMemberName()+"\n";
        }
    }
    //8.75% tax
    dues = (preferredCount * 75) + (basicCount * 60);
    //std::cout << "grand total but not the string:" <<grandTotal<<"|\n";
    dueStream << dues;
    out += "\nTotal Dues for this month: $";
    out += dueStream.str();
    out += "\n";


    return out;
}

/****************************************************************
* void addMember(string name, string id, string type, Date date)
* Accessor; This method set the member with input name id type and
  member expire date
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::addMember(string name, string id, string type, Date date)
{
    Member add(id, date, name, type);
    memberList.push_back(add);
    //after any list edit
    updateInfo();

}

/****************************************************************
* void addMember(string name, string id, string type, unsigned month, unsigned day, unsigned year
* Accessor; This method set the member with input name id type and
  member expire date
* --------------------------------------------------------------
* Parameters: string unsigned
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::addMember(string name, string id, string type, unsigned month, unsigned day, unsigned year)
{
    Date a(month,day,year);
    Member add(id, a, name, type);
    memberList.push_back(add);
    //after any list edit
    updateInfo();
}

/****************************************************************
* void deleteMember(string id)
* Accessor; This method delete member in member list
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::deleteMember(string id)
{
    int del;
    for(del = 0; del < memberList.length(); del++)
    {
        //only one unique ID per member
        if (id == memberList[del].getMemberId())
            memberList.delete_nth(del);
    }
    deleteMemberPurchases(id);
    //after any list edit
    updateInfo();
}

/****************************************************************
* void createPurchase(Date purchaseDate, string memberID, string productName, double price, int quantity)
* Accessor; This method push purchase to purchaseList with input
 purchase info
* --------------------------------------------------------------
* Parameters: string Date double int
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::createPurchase(Date purchaseDate, string memberID, string productName, double price, int quantity)
{
    Purchase a(purchaseDate, memberID, productName, price, quantity);
    purchaseList.push_back(a);
    //after any list edit
    updateInfo();
}

/****************************************************************
* void deletePurchase(Date purchaseDate, string memberID, string productName, double price, int quantity)
* Accessor; This method delete purchase from purchaseList with input
 purchase info
* --------------------------------------------------------------
* Parameters: string Date double int
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::deletePurchase(string memberID)
{
    //for loop to delete spcific purchase
    for(int i = 0;i < purchaseList.length(); i++)
    {
        if(memberID == purchaseList[i].getMemberID())
        {
            purchaseList.delete_nth(i);
        }
    }
    //after any list edit
    updateInfo();

}

/****************************************************************
* bool shouldSwitchBasic(string memberID)
* Accessor; This method return true if input id member is qualified
to switch to preferred member
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: true / false
***************************************************************/
bool InfoInterface::shouldSwitchPreferred(string memberID)
{
    Date expiry;
    Date yearBeforeExpiry;
    double purchaseTotal = 0;
    double grandTotal = 0;
    //find expiration date
    for(int i = 0;i < memberList.length(); i++)
    {
        if((memberID == memberList[i].getMemberId()))
        {
            expiry = memberList[i].getMemberExpiredDate();
        }
    }
    yearBeforeExpiry = expiry;
    // to see purchases before expiry
    yearBeforeExpiry.setYear(yearBeforeExpiry.getYear()-1);
    //for loop to to find all purchases within the year before expiry
    for(int i = 0;i < purchaseList.length(); i++)
    {
        //for each purchase
        if((memberID == purchaseList[i].getMemberID())
                && (yearBeforeExpiry< purchaseList[i].getPurchaseDate())
                && (purchaseList[i].getPurchaseDate() < expiry))
        {
            purchaseTotal = purchaseList[i].getProductPrice() * purchaseList[i].getProductQuantity();
            grandTotal += purchaseTotal;
        }
    }
    if ((grandTotal * REBATEPERCENT) >(PREFERREDYEARLY-BASICYEARLY))
        return true;
    else
        return false;

}

/****************************************************************
* void SwitchPreferred(string memberID)
* Accessor; This method set the member type to Preferred
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::SwitchPreferred(string memberID)
{
    //find member
    for(int i = 0;i < memberList.length(); i++)
    {
        if((memberID == memberList[i].getMemberId()))
        {
            memberList[i].setMemberType("Preferred");
        }
    }

    //after any list edit
    updateInfo();
}

/****************************************************************
* bool shouldSwitchBasic(string memberID)
* Accessor; This method return true if input id member is qualified
to switch to basic member
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: true / false
***************************************************************/
bool InfoInterface::shouldSwitchBasic(string memberID)
{
    Date expiry;
    Date yearBeforeExpiry;
    double purchaseTotal = 0;
    double grandTotal = 0;
    //find expiration date
    for(int i = 0;i < memberList.length(); i++)
    {
        if((memberID == memberList[i].getMemberId()))
        {
            expiry = memberList[i].getMemberExpiredDate();
        }
    }
    yearBeforeExpiry = expiry;
    // to see purchases before expiry
    yearBeforeExpiry.setYear(yearBeforeExpiry.getYear()-1);
    //for loop to to find all purchases within the year before expiry
    for(int i = 0;i < purchaseList.length(); i++)
    {
        //for each purchase
        if((memberID == purchaseList[i].getMemberID())
                && (yearBeforeExpiry< purchaseList[i].getPurchaseDate())
                && (purchaseList[i].getPurchaseDate() < expiry))
        {
            purchaseTotal = purchaseList[i].getProductPrice() * purchaseList[i].getProductQuantity();
            grandTotal += purchaseTotal;
        }
    }
    if ((grandTotal * REBATEPERCENT) < (PREFERREDYEARLY-BASICYEARLY))
        return true;
    else
        return false;

}

/****************************************************************
* void SwitchBasic(string memberID)
* Accessor; This method set the member type to Basic
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::SwitchBasic(string memberID)
{
    for(int i = 0;i < memberList.length(); i++)
    {
        if((memberID == memberList[i].getMemberId()))
        {
            memberList[i].setMemberType("Basic");
        }
    }
    //after any list edit
    updateInfo();
}


//use for #10-11, 11.2, 12.2
/****************************************************************
* void updateInfo()
* Accessor; This method will save changes made, uses FileManager
for #10-12 to make changes onto the respective .txt files
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::updateInfo()
{
//    //write info to member
//    //read in member files
//    writeMember();
//    ///write to each pre-existing day file both new and old data
//    for (int i = 0; i < files.numberDayFiles(); i++)
//        writePurchase(files.purchaseDayFiles[i].getFile(),i);

}

/****************************************************************
* bool ifPurchaseDayExists(Date day)
* Accessor; This method return true if input date in purchase list
* --------------------------------------------------------------
* Parameters: Date
* --------------------------------------------------------------
* Return: true / false
***************************************************************/
bool InfoInterface::ifPurchaseDayExists(Date day)
{
    for(int i = 0; i < purchaseList.length(); i++)
    {
        if (day == purchaseList[i].getPurchaseDate())
            return true;
    }
    return false;
}


/****************************************************************
* string getFullReport()
* MUTATOR; This method Rreturn example for concept
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: string
***************************************************************/
std::string InfoInterface::getFullReport(){
    std::string out = "";
    stringstream priceStream;
    stringstream quantityStream;
    stringstream dateStream;
    out += "Date\t\tID\tPrice\tQuant.\tName\n";
    for (int i = 0; i < purchaseList.length(); i++)
    {
        priceStream.str("");
        quantityStream.str("");
        dateStream.str("");
        priceStream.clear();
        quantityStream.clear();
        dateStream.clear();
        dateStream<<purchaseList[i].getPurchaseDate();
        out += dateStream.str() + "\t";
        out += purchaseList[i].getMemberID() + "\t";
        priceStream << purchaseList[i].getProductPrice();
        out +=  "$"+ priceStream.str();
        out += "\t";
        quantityStream << purchaseList[i].getProductQuantity();
        out += quantityStream.str() + "\t";
        out += purchaseList[i].getProductName();
        out += "\n";
    }
    return out;
}


/****************************************************************
* void deleteMemberPurchases(string memberID)
* Accessor; This method  helper in delete Member
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::deleteMemberPurchases(string memberID)
{
    bool deleting = true;
    //continue for for loop
    while (deleting)
    {
        //until every purchase with the memberID is gone
        for(int i = 0;i < purchaseList.length(); i++)
        {
            if(memberID == purchaseList[i].getMemberID())
            {
                purchaseList.delete_nth(i);
                deleting = true;
                break;
            }
            //if reached at end of for loop
            if((i == purchaseList.length()-1)
                    && (memberID != purchaseList[i].getMemberID()))
            {
                deleting = false;
            }
        }
    }
}

/****************************************************************
* bool alphabetOrder(string a, string b)
* Accessor; This method compares two string object, return true
*  in alphabet order
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: true / false
***************************************************************/
bool InfoInterface::alphabetOrder(string a, string b)
{
    int check = 0;
    if (a.length() <= b.length())
        check = a.length();
    else
        check = b.length();

    if(check == 0)
    {
        return true;
    }

    for(int i = 0; i < check ; i++)
    {
        if (a[i] < b[i])
            return false;
        else if (a[i] > b[i])
            return true;
        else
            return alphabetOrder(a.substr(1,a.length()-1),b.substr(1,b.length()-1));
    }

    return true;
}

/****************************************************************
* string findMemberID(string memberName)
* MUTATOR; This method Rreturn member if with input member name
* --------------------------------------------------------------
* Parameters: string
* --------------------------------------------------------------
* Return: string
***************************************************************/
string InfoInterface::findMemberID(string memberName)
{
    std::cout <<"Doing findMemberID\n";
    for (int i = 0; i < memberList.length(); i++)
    {
        if (memberName == memberList[i].getMemberName())
        {
            //std::cout <<"Member ID that was found is " << memberList[i].getMemberName();
            return memberList[i].getMemberId();
        }

    }

    return "";
}

/****************************************************************
* void writeMember()
* Accessor; This method write member info to txt file
* --------------------------------------------------------------
* Parameters: none
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::writeMember()
{
    //format based on read member

    fstream outFile;                                 //PROC-file to be processed

    std::string fullFile = FILEDIR + "members" + FILETYPE;        //PROC-tracks line count

    //write
    outFile.open(fullFile,ios::in);

    if(outFile.is_open())
    {
        for(int i = 0; i < memberList.length();i++)
        {
            outFile << memberList[i].getMemberName();
            outFile << "\n";
            outFile << memberList[i].getMemberId();
            outFile << "\n";
            outFile << memberList[i].getMemberType();
            outFile << "\n";
            outFile << memberList[i].getMemberExpiredDate();
            if (i!=memberList.length()-1)
                outFile << "\n";
        }
        outFile.close(); //close the file object.
    }
}

/****************************************************************
* void writePurchase(string purFile, int purFileIndex)
* Accessor; This method write purchase info to txt file
* --------------------------------------------------------------
* Parameters: string int
* --------------------------------------------------------------
* Return: none
***************************************************************/
void InfoInterface::writePurchase(string purFile, int purFileIndex)
{
//    //format based on read member
//    fstream outFile;                                 //PROC-file to be processed
//    int dayPurchaseTotalCounter = 0;
//    int dayPurchaseCounter = 0;

//    //write
//    outFile.open(purFile,ios::in);


//    //get count of days total purchases on that day
//    for(int i = 0; i < purchaseList.length();i++)
//    {
//        if (purchaseList[i].getPurchaseDate()==files.purchaseDayFiles[purFileIndex].getDate())
//            dayPurchaseTotalCounter++;
//    }

//    if(outFile.is_open())
//    {
//        //loop in the whole list
//        for(int i = 0; i < purchaseList.length();i++)
//        {
//            //writing all info for that day
//            if (purchaseList[i].getPurchaseDate() == files.purchaseDayFiles[purFileIndex].getDate())
//            {
//                outFile << purchaseList[i].getPurchaseDate();
//                outFile << "\n";
//                outFile << purchaseList[i].getMemberID();
//                outFile << "\n";
//                outFile << purchaseList[i].getProductName();
//                outFile << "\n";
//                outFile << purchaseList[i].getProductPrice();
//                outFile << "\t";
//                outFile << purchaseList[i].getProductQuantity();

//                dayPurchaseCounter++;
//                //as long as next purchase is not in the next file, separated by date
//                if (dayPurchaseCounter < dayPurchaseTotalCounter)
//                    outFile << "\n";
//            }
//        }
//        outFile.close(); //close the file object.
//    }

}

