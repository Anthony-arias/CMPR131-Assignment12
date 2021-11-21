// main.cpp

// Team: Anthony, An, Van, Vincent, Nhan
// Chapter 12: 
// 10/7/2021

#include <iostream>
#include <string>
#include "optionOne.h"
#include "optionTwo.h"
#include "optionThree.h"
#include "input.h"
#include "menus.h"

void mainMenu(void);
void programOne(void);
void programTwo(void);
void programThree(void);

using namespace std;

int main(void)
{
    mainMenu();
    return 0;
}

//PreCondition: NA
//PostCondition: redirects user to different menus based on their choice
void mainMenu(void)
{
    do
    {
        clearScreen();

        displayMainMenu();

        int userInput = inputInteger("\t\tOption: ", 0, 3);
        switch (userInput)
        {
        case 0: return;
        case 1: programOne(); break;
        case 2: programTwo(); break;
        case 3: programThree(); break;
        default: cout << "\t\tERROR-3A: Invalid input. Must be from 0..3." << endl;
        }

    } while (true);
}

//PreCondition: NA
//PostCondition: 
void programOne(void)
{
    
    vector<string>array;
    do
    {
        clearScreen();
        displayOptionOneMenu();
        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': initArray(array); break;
        case 'b': case 'B': push(array); break;
        case 'c': case 'C': display(array); break;
        case 'd': case 'D': search(array); break;
        case 'e': case 'E': clearArray(array); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
        }
        cout << endl;
        pause("\n\t\tPress enter to continue...");
    } while (true);
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    do
    {
        displayOptionTwoMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': /*function here*/ break;
        case 'b': case 'B': /*function here*/ break;
        case 'c': case 'C': /*function here*/ break;
        case 'd': case 'D': /*function here*/ break;
        case 'e': case 'E': /*function here*/ break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}

//PreCondition: NA
//PostCondition: 
void programThree(void)
{
    do
    {
        clearScreen();
        displayOptionThreeMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': /*function here*/ break;
        case 'b': case 'B': /*function here*/  break;
        case 'c': case 'C': /*function here*/  break;
        case 'd': case 'D': /*function here*/  break;
        case 'e': case 'E': /*function here*/  break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}
