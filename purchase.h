#ifndef PURCHASE_H
#define PURCHASE_H
#include "date.h"
#include <string>
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
    Date getPurchaseDate();

    void setMemberID(string id);
    string getMemberID();

    void setProductName(string name);
    string getProductName();

    void setProductPrice(double price);
    double getProductPrice();

    void setProductQuantity(unsigned amount);
    unsigned getProductQuantity();

private:
    Date _purchaseDate;
    std::string _memberID;
    std::string _productName;
    double _price;
    unsigned _quantity;
};

#endif // PURCHASE_H
