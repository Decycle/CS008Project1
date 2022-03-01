#include "purchase.h"

#include <utility>

Purchase::Purchase()
{
    _purchaseDate = Date();
    _memberID ="";
    _price =0.0;
    _productName = "";
    _quantity =0;
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
    _purchaseDate = Date(month,day,year);
    _memberID = std::move(memberID);
    _productName = std::move(productName);
    _price = price;
    _quantity = quantity;

}
Purchase::Purchase(string memberID,string productName,double price, unsigned quantity, string date){
    setMemberID(memberID);
    setProductName(productName);
    setProductPrice(price);
    setProductQuantity(quantity);
    setPurchaseDate(date);
}

string Purchase::print(){
    return "Product: [" + this->getPurchaseDate_string()+ "], ["+ this->getMemberID() + "], ["+this->getProductName()+"], ["
            + to_string(this->getProductPrice())+"], ["+ to_string(this->getProductQuantity()) +"]\n";
}

void Purchase::setPurchaseDate(Date date)
{
    _purchaseDate = std::move(date);
}
void Purchase::setPurchaseDate(string date){
    //Date temp(std::move(date));
    //_purchaseDate = std::move(temp);
    date >> _purchaseDate;
}
Date Purchase::getPurchaseDate()
{
    return _purchaseDate;
}
string Purchase::getPurchaseDate_string(){
    return _purchaseDate.print();
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
