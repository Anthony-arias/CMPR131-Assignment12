// menus.h

#include <iostream>
#include <string>

using namespace std;

//PreCondition: NA
//PostCondition: displays main menu options
void displayMainMenu(void)
{
    cout << "\n\tCMPR131 Chapter 12: Searches and hashing by Anthony, An, Van, Vincent, Nhan (10/7/21)" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\t1> Searching from an unsorted dynamic array" << endl;
    cout << "\t\t2> Searching from a sorted dynamic array" << endl;
    cout << "\t\t3> Application using hashing" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> exit" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\t1> Searching unsorted dynamic arrays" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Read random string data and store into the dynamic array" << endl;
    cout << "\t\tB> Add an element to the dynamic array" << endl;
    cout << "\t\tC> Display elements from the array" << endl;
    cout << "\t\tD> Search for an element from the array" << endl;
    cout << "\t\tE> Clear the array" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option two menu options
void displayOptionTwoMenu(void)
{
    cout << "\n\t2> Searching sorted dynamic arrays" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Read data file and store into the array" << endl;
    cout << "\t\tB> Add an element to the dynamic array" << endl;
    cout << "\t\tC> Display elements from the array" << endl;
    cout << "\t\tD> Search for an element from the array" << endl;
    cout << "\t\tE> Clear the array" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}

//PreCondition: NA
//PostCondition: displays option three menu options
void displayOptionThreeMenu(void)
{
    cout << "\n\t3> Application using hashing" << endl;
    cout << "\t" + string(100, char(205)) << endl;
    cout << "\t\tA> Read data file, hash and insert into the dynamic array" << endl;
    cout << "\t\tB> Search an element from the dynamic array" << endl;
    cout << "\t\tC> Insert an element into the dynamic array" << endl;
    cout << "\t\tD> Remove an element from the dynamic array" << endl;
    cout << "\t\tE> Display all records from the array" << endl;
    cout << "\t" + string(100, char(196)) << endl;
    cout << "\t\t0> return" << endl;
    cout << "\t" + string(100, char(205)) << endl;
}