#include "purchase.h"

Purchase::Purchase()
{

}

Purchase::Purchase(Date purchaseDate,
                   std::string memberID,
                   std::string productName,
                   double price,
                   unsigned quantity)
{
    _purchaseDate = purchaseDate;
    _memberID = memberID;
    _productName = productName;
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
    _purchaseDate = Date(month,day,year);
    _memberID = memberID;
    _productName = productName;
    _price = price;
    _quantity = quantity;

}

void Purchase::setPurchaseDate(Date date)
{
    _purchaseDate = date;
}

Date Purchase::getPurchaseDate()
{
    return _purchaseDate;
}

void Purchase::setMemberID(string id)
{
    _memberID = id;
}

string Purchase::getMemberID()
{
    return _memberID;
}

void Purchase::setProductName(string name)
{
    _productName = name;
}

string Purchase::getProductName()
{
    return _productName;
}

void Purchase::setProductPrice(double price)
{
    _price = price;
}

double Purchase::getProductPrice()
{
    return _price;
}

void Purchase::setProductQuantity(unsigned amount)
{
    _quantity = amount;
}

unsigned Purchase::getProductQuantity()
{
    return _quantity;
}
