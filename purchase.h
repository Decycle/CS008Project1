#ifndef PURCHASE_H
#define PURCHASE_H
#include "date.h"
#include <iostream>
#include <string>

using namespace std;
class Purchase
{
public:
    Purchase();
    Purchase(Date purchaseDate,
             std::string memberID,
             std::string productName,
             double price,
             unsigned quantity);
    Purchase(unsigned month,
             unsigned day,
             unsigned year,
             std::string memberID,
             std::string productName,
             double price,
             unsigned quantity);

    void setPurchaseDate(Date date);
    Date getPurchaseDate() const;

    void setMemberID(string id);
    string getMemberID() const;

    void setProductName(string name);
    string getProductName() const;

    void setProductPrice(double price);
    double getProductPrice() const;

    void setProductQuantity(unsigned amount);
    unsigned getProductQuantity() const;

    void print() const;

private:
    Date _purchaseDate;
    std::string _memberID;
    std::string _productName;
    double _price;
    unsigned _quantity;
};

#endif // PURCHASE_H
