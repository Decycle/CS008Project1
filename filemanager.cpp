#include "filemanager.h"


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
        ss.str(line);
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

//FileManager::FileManager()
//{
//    memberfile = "warehouse shopppers";
//    std::string FILETYPE = ".txt";                  //CONSTANT-file type
//    std::string FILEDIR = "..\\WarehouseReport\\";    //CONSTANT-auto directory path
//    //find each day file
//    fstream infile;
//    std::string line;

//    std::string fullFile;

//    stringstream ss;
//    int count = 1;
//    ss << count;
//    std::string stringCount = ss.str();

//    fullFile = FILEDIR + "day" + stringCount + FILETYPE;
//    infile.open(fullFile,ios::in);

//    //tests if first open works
//    if(infile.is_open()){
//    //while loop until not good

//        while(infile.is_open()){
//            //line is the whole string
//            getline(infile,line);
//            //should reset each loop
//            Dayfile a = Dayfile();
//            //should reset each loop
//            Date day = Date();
//            //feeds line into day
//            line >> day;
//            //sets the date in dayfile
//            a.setDate(day);
//            //sets the full file
//            a.setfile(fullFile);
//            purchaseDayFiles.push_back(a);

//            infile.close();
//            count++;
//            ss.str("");
//            ss.clear();
//            ss << count;
//            std::string stringCount = ss.str();
//            fullFile = FILEDIR + "day" + stringCount + FILETYPE;
//            infile.open(fullFile,ios::in);
//        }
//    }
//}


////for finding specific days
//string FileManager::getdayfile(Date day)
//{
//    for(int i = 0; i < purchaseDayFiles.length(); i++)
//    {
//        //if the date matches
//        if(day == purchaseDayFiles[i].getDate())
//            return purchaseDayFiles[i].getFile();
//    }
//}

//std::string FileManager::getMemberFile()
//{
//    return memberfile;
//}

//int FileManager::numberDayFiles()
//{
//    return purchaseDayFiles.length();
//}
