#include "purchase.h"

#include <utility>

Purchase::Purchase()
{
}

Purchase::Purchase(Date purchaseDate,
                   std::string memberID,
                   std::string productName,
                   double price,
                   unsigned quantity)
{
    _purchaseDate = std::move(purchaseDate);
    _memberID = std::move(memberID);
    _productName = std::move(productName);
    _price = price;
    _quantity = quantity;
}
Purchase::Purchase(unsigned month,
                   unsigned day,
                   unsigned year,
                   std::string memberID,
                   std::string productName,
                   double price,
                   unsigned quantity)
{
    _purchaseDate = Date(month, day, year);
    _memberID = std::move(memberID);
    _productName = std::move(productName);
    _price = price;
    _quantity = quantity;
}

void Purchase::setPurchaseDate(Date date)
{
    _purchaseDate = std::move(date);
}

Date Purchase::getPurchaseDate()
{
    return _purchaseDate;
}

void Purchase::setMemberID(string id)
{
    _memberID = std::move(id);
}

string Purchase::getMemberID()
{
    return _memberID;
}

void Purchase::setProductName(string name)
{
    _productName = std::move(name);
}

string Purchase::getProductName()
{
    return _productName;
}

void Purchase::setProductPrice(double price)
{
    _price = price;
}

double Purchase::getProductPrice() const
{
    return _price;
}

void Purchase::setProductQuantity(unsigned amount)
{
    _quantity = amount;
}

unsigned Purchase::getProductQuantity() const
{
    return _quantity;
}
