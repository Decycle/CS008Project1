#include "filemanager.h"

#include <QDebug>


LinkedList<Purchase> FileManager::readDayFile(string fileName)
{
    LinkedList<Purchase> purchases;
    ifstream infile;
    infile.open(fileName);
    string line;
    stringstream ss;

    while(true)
    {

        if(!getline(infile, line)) break;
        //Date
        Date d;
        line >> d;

        if(!getline(infile, line)) break;
        //ID
        ss.str(line);
        string id;
        ss >> id;

        if(!getline(infile, line)) break;
        //Name
        string name;
        name = line;

        if(!getline(infile, line)) break;
        //Price and Quantity
        ss.str(line);
        double price;
        int quantity;

        ss >> price >> quantity;

        Purchase p(d, id, name, price, quantity);
        purchases.push_back(p);
    }
    infile.close();
    return purchases;
}
LinkedList<Member> FileManager::readMemberFile(string fileName)
{
    LinkedList<Member> members;
    ifstream infile;
    infile.open(fileName);
    string line;
    stringstream ss;

    while(true)
    {
        if(!getline(infile, line)) break;
        //Name
        string name;
        name = line;

        if(!getline(infile, line)) break;
        //ID
        ss.str(line);
        string id;
        ss >> id;

        if(!getline(infile, line)) break;
        //Type
        ss.str(line);
        string type;
        ss >> type;

        if(!getline(infile, line)) break;
        //Date
        Date d;
        line >> d;

        Member m(id, d, name, type);
        members.push_back(m);
    }
    infile.close();
    return members;
}
