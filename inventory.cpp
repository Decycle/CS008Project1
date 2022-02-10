#include "inventory.h"

Inventory::Inventory()
{
    totalquant = 0;
}

map<string,map<double,int>> Inventory::add(string filename)
{
    fstream file;
    file.open(filename);
    string line;

    string itemname;

    string pricestr;
    double itemprice;

    string quantstr;
    int itemquant;

    int linecount = 0;

    if(file)
    {
        while( getline(file, line))
        {
            linecount++;
//            cout<<linecount<<" ";
//            cout<<line<<endl;
            if( linecount % 2 == 0)
            {
                //will pull name from every third line into variable itemname
                getline(file,itemname,'\n');
                //will pull 4th line before the tab into the variable pricestr
                getline(file,pricestr,'\t');
                //converts from string to double
                itemprice = stod(pricestr);
                //pulls from every 4th line after tab into quantstr var
                getline(file,quantstr,'\n');
                //string to int convert
                itemquant = stoi(quantstr);
                //inserting values into map, just first value/ item name
                inv.insert(make_pair(itemname,map<double,int>()));
                //inserting pricing and quantity of each item
                inv[itemname].insert(make_pair(itemprice,itemquant));
            }
        }
    }
    else
    {
        throw "file isnt open";
    }

    file.close();

    return inv;
}
void Inventory::print(map<string, map<double, int>> inv)
{
    map<string, map<double, int>>::iterator row;
    map<double, int>::iterator col;
    cout<<setw(25)<<left<<" Item names"<<"|"
        <<setw(10)<<left<<"Price"<<"|"
        <<setw(20)<<left<<"Quantity"<<endl;
    for(row = inv.begin(); row!= inv.end(); row++)
    {
        for(col = row->second.begin();col != row->second.end();col++)
        {
            cout<<setw(26)<<left<<row->first
                <<setw(12)<<left<<col->first
                <<setw(20)<<left<<col->second
                <<endl;
        }

    }
}
