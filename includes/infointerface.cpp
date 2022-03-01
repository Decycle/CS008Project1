#include "infointerface.h"

InfoInterface::InfoInterface()
{
    //read in member files
    readMember();
    //files.getMemberFile();

    ///read in each day file
    //readPurchase();
}

InfoInterface::~InfoInterface(){
    memberList.clear();
    purchaseList.clear();
}

string InfoInterface::getDayReport(Date day)
{

}

void InfoInterface::readMember()
{
    fstream infile;                                 //PROC-file to be processed
    std::string memFile = files.getMemberFile();

    string line;

    std::string fullFile = FILEDIR + memFile + FILETYPE;
    int memberCount= 0;//PROC-tracks line count


    infile.open("warehouse shoppers.txt",ios::in);

    //cout<<__LINE__ << endl;

     if(infile.fail()){
//         cout << "Open file failed.\n";
//         exit(1);
            //cout<<__LINE__ << endl;
        cout << "FILE OPENING ERROR!! "
            "\nchecking if included "
            ".txt in user input" << endl;
        infile.open(FILEDIR + memFile,ios::in);
        //check if file is good
        if (!infile.good())
            cout << "file name does not work" << endl;

     }


    do{
        Member each = Member();         //sets to default each time
        Date eachExpire = Date();       //sets to default each time
        //gets 1st line for name
        getline(infile, line);
        each.setMemberName(line);
        //gets 2nd line for ID
        getline(infile, line);
        each.setMemberId(line);
        //gets 3nd line for Member Type
        getline(infile, line);
        each.setMemberType(line);
        //gets 4th line for Member Type
        getline(infile, line);
        each.setMemberExpiredDate(line);


        //each.print();

        memberList.push_back(each);
        //cout <<__LINE__<< endl;
        memberCount++;
        //cout << memberCount << endl;
    }while(!infile.eof());

    infile.close(); //close the file object.
}

void InfoInterface::addMember(Member add){
    if(findMember(add))
        return;
    else
        memberList.push_back(add);
}

void InfoInterface::deleteMember(Member del){

    //int index=0;
    LinkedList<Member> temp;
    for(int i=0; i<memberList.length();){

        if(memberList[i].getMemberId() == del.getMemberId()){
            i++;
        }
        //index =i;
        else{
            temp.push_back(memberList[i]);
            i++;
        }

    }
    memberList.clear();
    for(int i=0; i<temp.length();i++){
         memberList.push_back(temp[i]);
    }

}

bool InfoInterface::findMember(Member member){
    for(int i=0; i<memberList.length();i++){
        if(memberList[i].getMemberId() == member.getMemberId())
            return true;
    }
    return false;
}

int InfoInterface::findMemberIndex(string memberID){

    for(int i=0; i<memberList.length();i++){
        if(memberList[i].getMemberId() == memberID)
            return i;
    }
    return -1;
}

int InfoInterface::findMemberIndex2(string member_name){
    for(int i=0; i<memberList.length();i++){
        if(memberList[i].getMemberName() == member_name)
            return i;
    }
    return -1;
}
bool InfoInterface::shouldSwitchPreferred(std::string memberID){

}

//11.2 actually do 11.1
void InfoInterface::SwitchPreferred(std::string memberID){
    memberList[findMemberIndex(memberID)].upgradeMember();
}
bool InfoInterface::SwitchBasic(std::string memberID){
    memberList[findMemberIndex(memberID)].downgradeMember();
}

void InfoInterface::readPurchase()
{
    fstream in;                                 //PROC-file to be processed
    string line;
    double price;
    int quantity;
    in.open("day0.txt", ios::in);

    //cout<<__LINE__ << endl;

    if(in.fail()){
         cout << "Open file failed.\n";
         exit(1);
    }


    //getline(in,line);
    do{
        Purchase each = Purchase();
        Date eachExpire = Date();

        getline(in,line);
        each.setPurchaseDate(line);

        getline(in, line);
        each.setMemberID(line);

        getline(in, line);
        each.setProductName(line);

        in>> price;
        each.setProductPrice(price);

        in >> quantity;
        each.setProductQuantity(quantity);


        //each.print();

        purchaseList.push_back(each);
        //cout <<__LINE__<< endl;

    }while(!in.eof());

    in.close(); //close the file object.
}

string getYearReport(unsigned year){

}

//3 A user should be able to enter a membership number or name and get
//a list of the total purchases per that member.
void InfoInterface::getMemberNumberReport(std::string memberID){
    LinkedList<Purchase> temp;
    string report ="";
    for(int i=0;i< purchaseList.length(); i++){
        if(purchaseList[i].getMemberID() == memberID){
            temp.push_back(purchaseList[i]);
        }
    }

    //return purchaseList.display();
    for(int i=0; i<temp.length(); i++){
        report += purchaseList[i].print();
        report += "\n";
    }

    //ui->setText(report)
}

string InfoInterface::getMemberNameReport(std::string memberName){
    int index = findMemberIndex2(memberName);
    string temp_id = memberList[index].getMemberId();
    LinkedList<Purchase> temp;
    string report ="";

    for(int i=0;i< purchaseList.length(); i++){
        if(purchaseList[i].getMemberID() == temp_id){
            temp.push_back(purchaseList[i]);
        }
    }

    for(int i=0; i<temp.length(); i++){
        report +=purchaseList[i].print();
        report +="";
    }

    //ui->setText(report)
}
//4,sorted by member ID
//include a grand total of the purchases.
string InfoInterface::getTotalMemberReport(){

}

string InfoInterface::getItemReport(std::string itemName){

}

string InfoInterface::getItemTotalReport(std::string itemName){

}

string InfoInterface::getRebateReport(){

}