#ifndef INVENTORY_H
#define INVENTORY_H
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Inventory
{
public:
    Inventory();
    void pull();                                                         // pulls single item
    map<string,map<double,int>> add(string filename);                    // adds 'amount' amount of items into inventory
    int totalquantity(){return totalquant;}                              // total quantity of all items, returns total
    void print(map<string, map<double, int> > inv);

private:
    map<string, map<double, int>> inv;                                    //2d map to store inventory

    int totalquant;                                                       // total quantity of all items in inventory
};

#endif // INVENTORY_H
