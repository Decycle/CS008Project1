#include <iostream>
#include "member.h"
#include <fstream>
#include "date.h"
#include "filemanager.h"
using namespace std;

int main()
{
    FileManager a;
    cout << "number of day files: " << a.numberDayFiles() <<endl;

    for (int i = 0; i < a.numberDayFiles();i++)
        cout << a.purchaseDayFiles[i].getFile() << endl;
    for (int i = 0; i < 10;i++){
         Dayfile a = Dayfile();

    }
    for (int i = 0; i < 10;i++){
        //constructor rest works
        Date day = Date(i,i,i);
        day = Date();
        day.printNumeric();
        cout << endl;
    }

//    std::string memberfile = "warehouse shopppers";
//    std::string FILETYPE = ".txt";                  //CONSTANT-file type
//    std::string FILEDIR = "..\\testfilereal\\";    //CONSTANT-auto directory path
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
//            getline(infile,line);
//            //line is the whole string
//            std::cout << line;





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
}
