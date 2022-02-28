#include "infointerface.h"

InfoInterface::InfoInterface()
{
    // read in member files
    readMember();
    // files.getMemberFile();

    /// read in each day file
    readPurchase();
}

InfoInterface::~InfoInterface()
{
    memberList.clear();
    purchaseList.clear();
}

string InfoInterface::getDayReport(Date day)
{
}

void InfoInterface::readMember()
{
    fstream infile; // PROC-file to be processed
    std::string memFile = files.getMemberFile();

    string line;

    std::string fullFile = FILEDIR + memFile + FILETYPE;
    int memberCount = 0; // PROC-tracks line count

    infile.open("warehouse shoppers.txt", ios::in);

    // cout<<__LINE__ << endl;

    if (infile.fail())
    {
        //         cout << "Open file failed.\n";
        //         exit(1);
        // cout<<__LINE__ << endl;
        cout << "FILE OPENING ERROR!! "
                "\nchecking if included "
                ".txt in user input"
             << endl;
        infile.open(FILEDIR + memFile, ios::in);
        // check if file is good
        if (!infile.good())
            cout << "file name does not work" << endl;
    }

    do
    {
        Member each = Member();   // sets to default each time
        Date eachExpire = Date(); // sets to default each time
        // gets 1st line for name
        getline(infile, line);
        each.setMemberName(line);
        // gets 2nd line for ID
        getline(infile, line);
        each.setMemberId(line);
        // gets 3nd line for Member Type
        getline(infile, line);
        each.setMemberType(line);
        // gets 4th line for Member Type
        getline(infile, line);
        each.setMemberExpiredDate(line);

        // each.print();

        memberList.push_back(each);
        // cout <<__LINE__<< endl;
        memberCount++;
        cout << memberCount << endl;
    } while (!infile.eof());

    infile.close(); // close the file object.
}

void InfoInterface::addMember(Member add)
{
    if (findMember(add))
        return;
    else
        memberList.push_back(add);
}

void InfoInterface::deleteMember(Member del)
{

    // int index=0;
    LinkedList<Member> temp;
    for (int i = 0; i < memberList.length();)
    {

        if (memberList[i].getMemberId() == del.getMemberId())
        {
            i++;
        }
        // index =i;
        else
        {
            temp.push_back(memberList[i]);
            i++;
        }
    }
    memberList.clear();
    for (int i = 0; i < temp.length(); i++)
    {
        memberList.push_back(temp[i]);
    }
}

bool InfoInterface::findMember(Member member)
{
    for (int i = 0; i < memberList.length(); i++)
    {
        if (memberList[i].getMemberId() == member.getMemberId())
            return true;
    }
    return false;
}

void InfoInterface::readPurchase()
{
}
