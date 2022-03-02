#include "infointerface.h"

InfoInterface::InfoInterface()
{

}
//{
//    //read in member files
//    readMember();
//    //files.getMemberFile();

//    ///read in each day file
//    readPurchase();
//}

//string InfoInterface::getDayReport(Date day)
//{

//}

//void InfoInterface::readMember()
//{
//    fstream infile;                                 //PROC-file to be processed
//    std::string memFile = files.getMemberFile();

//    string line;

//    std::string fullFile = FILEDIR + memFile + FILETYPE;
//    int memberCount= 0;                                //PROC-tracks line count
//    infile.open(fullFile,ios::in);
//    if(infile.is_open())
//    {

//            while(infile.is_open())
//            {
//                Member each = Member();         //sets to default each time
//                Date eachExpire = Date();       //sets to default each time
//                //gets 1st line for name
//                getline(infile, line);
//                each.setMemberName(line);
//                //gets 2nd line for ID
//                getline(infile, line);
//                each.setMemberId(line);
//                //gets 3nd line for Member Type
//                getline(infile, line);
//                each.setMemberType(line);
//                //gets 4th line for Member Type
//                getline(infile, line);
//                each.setMemberExpiredDate(line);


//                memberCount++;
////                strCount = infile.getline(str,MAXCHAR).gcount();
////                //cout <<"line length: "<<strCount <<"\n";
////                //accounts for the line line where \n is not there
////                if (str[strCount-1]=='\n')
////                    strCount--;
////                //cout <<"line length corrected: "<<strCount <<"\n";
////                //cout <<"str contents:"<<str<<"||||\n";
////               //PROCESSING HERE BELOW THIS LINE






////                //PROCESSING HERE ABOVE THIS LINE
////                //resets char array
////                for(int i = 0; i < strCount; ++i)
////                {
////                  str[i] = (char)0;
////                }
////                //char array count
////                strCount = 0;
//            }
//            infile.close(); //close the file object.
//    }

//}

//void InfoInterface::readPurchase()
//{

//}
