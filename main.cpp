#include <iostream>
#include "includes/member.h"
#include "includes/infointerface.h"
using namespace std;

void testInterface()
{
    InfoInterface infoin;

    infoin.print();

    Member m2 = Member("jack2", "24", "per", "12/13/2012");

    cout << "-------------test addMember------------------------\n";
    infoin.addMember(m2);
    infoin.print();
    cout << "-------------test delete Member------------------------\n";
    infoin.deleteMember(m2);
    infoin.print();
}
int main()
{

    // testList();
    // testmember();
    //    report repo;
    //    repo.print_member();

    testInterface();

    // testList();
    return 0;
}