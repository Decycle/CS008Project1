#ifndef PURCHASE_H
#define PURCHASE_H
#include "date.h"
#include <string>
#include <iostream>

using namespace std;
class Purchase
{
public:
    Purchase();
    Purchase(Date purchaseDate, std::string memberID, std::string productName,
             double price, unsigned quantity);

    Purchase(unsigned month, unsigned day, unsigned year,
             std::string memberID, std::string productName,
             double price, unsigned quantity);

    Purchase(string memberID,string productName,double price, unsigned quantity, string date);

    void setPurchaseDate(Date date);
    void setPurchaseDate(string date);
    Date getPurchaseDate();
    string getPurchaseDate_string();

    void setMemberID(string id);
    string getMemberID();

    void setProductName(string name);
    string getProductName();

    void setProductPrice(double price);
    double getProductPrice() const;

    void setProductQuantity(unsigned amount);
    unsigned getProductQuantity() const;

    string print();

private:
    Date _purchaseDate;
    std::string _memberID;
    std::string _productName;
    double _price;
    unsigned _quantity;
};

#endif // PURCHASE_H
