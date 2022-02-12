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
