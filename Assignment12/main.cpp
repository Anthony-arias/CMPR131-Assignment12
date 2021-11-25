// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 12: 
// 10/7/2021

#include <iostream>
#include <string>
#include "dynamicArray.h"
#include "optionThree.h"
#include "input.h"
#include "hashTable.h"
#include <list>
void programOne(void);
void programTwo(void);
void programThree(void);

using namespace std;

//PreCondition: NA
//PostCondition: Main function
int main(void)
{
    do
    {
        clearScreen();

        cout << "\n\tCMPR131 Chapter 12: Searches and hashing by Anthony, An, Van, Vincent, Nhan (10/7/21)" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        cout << "\t\t1> Searching from an unsorted dynamic array" << endl;
        cout << "\t\t2> Searching from a sorted dynamic array" << endl;
        cout << "\t\t3> Application using hashing" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        cout << "\t\t0> exit" << endl;
        cout << "\t" + string(100, char(205)) << endl;

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: exit(1); break;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
    return EXIT_SUCCESS;
}

//PreCondition: NA
//PostCondition: Searching from an unsorted dynamic array
void programOne(void)
{

    vector<string>array;
    do
    {
        clearScreen();

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

        int option = inputChar("\t\tOption: ");


        switch (option)
        {
        case '0': return;
        case 'A': initArray(array,false); break;
        case 'B': push(array,false); break;
        case 'C': display(array); break;
        case 'D': search(array,false); break;
        case 'E': clearArray(array); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}


//PreCondition: NA
//PostCondition: Searching from a sorted dynamic array
void programTwo(void)
{
    vector<string>array;
    do
    {
        clearScreen();
        cout << "\n\t2> Searching sorted dynamic arrays" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        cout << "\t\tA> Read random string data and store into the dynamic array" << endl;
        cout << "\t\tB> Add an element to the dynamic array" << endl;
        cout << "\t\tC> Display elements from the array" << endl;
        cout << "\t\tD> Search for an element from the array" << endl;
        cout << "\t\tE> Clear the array" << endl;
        cout << "\t" + string(100, char(196)) << endl;
        cout << "\t\t0> return" << endl;
        cout << "\t" + string(100, char(205)) << endl;
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'A': initArray(array, true); break;
        case 'B': push(array, true); break;
        case 'C': display(array); break;
        case 'D': search(array, true); break;
        case 'E': clearArray(array); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}

//PreCondition: NA
//PostCondition: Application using hashing
void programThree(void)
{
    int totalRecords = 0;
    list<student>studentList;
    hashTable table;
    do
    {
        clearScreen();
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
        int option = inputChar("\t\tOption: ");
        switch (option)
        {
        case '0': return;
        case 'A': readfile(totalRecords, table); break;
        case 'B': hashSearch(table);  break;
        case 'C': insertStudent(table);  break;
        case 'D': removeStudent(table);  break;
        case 'E': table.display();  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}

