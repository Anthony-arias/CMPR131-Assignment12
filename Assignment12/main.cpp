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
    DynamicString dynamicString;

    do
    {
        displayOptionOneMenu();
        int option = inputChar("\t\tOption: ");


        switch (option)
        {
        case '0': return;
        case 'a': case 'A': A(dynamicString); break;
        case 'b': case 'B': B(dynamicString); break;
        case 'c': case 'C': C(dynamicString); break;
        case 'd': case 'D': D(dynamicString); break;
        case 'e': case 'E': E(dynamicString); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C','D', or 'E'" << endl;
            pause("\n\t\tPress enter to continue...");
        }
    } while (true);
}


//PreCondition: NA
//PostCondition: 
void programTwo(void)
{
    DynamicString dynamicString;

    do
    {
        displayOptionTwoMenu();

        int option = inputChar("\t\tOption: ");

        switch (option)
        {
        case '0': return;
        case 'a': case 'A': A2(dynamicString); break;
        case 'b': case 'B': B2(dynamicString); break;
        case 'c': case 'C': C2(dynamicString); break;
        case 'd': case 'D': D2(dynamicString); break;
        case 'e': case 'E': E2(dynamicString); break;
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
