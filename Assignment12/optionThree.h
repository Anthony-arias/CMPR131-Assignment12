// optionThree.h

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include <fstream>
#include "Student.h"
#include "input.h"
#include "hashTable.h"
#include<sstream>
#include <list>

using namespace std;

//PreCondition: input source file, student, and hashTable
//PostCondition: Adds new student into the table
void addOneRecord(fstream& source, student& s, hashTable& table)
{
    string line;
    if (getline(source, line, ','))
    {
        int ID = stoi(line);
        s.setID(ID);
        getline(source, line, ',');
        s.setName(line);
        getline(source, line, ',');
        s.setMajor(line);
        getline(source, line);
        double score = stod(line);
        s.setGPA(score);
        table.insertItem(s);
    }
}

//PreCondition: input total records and hashTable 
//PostCondition: Read data from the Students.dat file and stored into the hashTable
void readfile(int &totalRecords, hashTable &table)
{
    totalRecords = 0;
    table.clear();
    fstream source;
    string fileName = "Students.dat";
    source.open(fileName);
    if (!source)
        cout << "\n\t\tERROR: Cannot find the file: " << fileName << endl;
    else
    {
        string s;
        getline(source, s);
        while (source)
        {
            getline(source, s);
            totalRecords++;
        }
    }
    source.close();
    source.open(fileName);
    table.setSize(totalRecords);
    int readInRecords = inputInteger("\n\t\tEnter a number of read-in records: from 1.." + to_string(totalRecords) + ": ", 1, totalRecords);
	int count = 0;
	while (source && count < readInRecords)
	{
		if (source.fail()) break;
		else
		{
			student newStudent;
			addOneRecord(source, newStudent, table);
			count++;
		}
	}
	source.close();
	if (table.getSize() == 1)
		cout << "\n\t\t" << table.getSize() << " record have been inserted." << endl;
	else
        cout << "\n\t\t" << table.getSize() << " records have been inserted." << endl;
    
}


//PreCondition: input hashTable 
//PostCondition: insert new student into the hashTable
void insertStudent(hashTable table)
{
    student s;
    s.setID(inputInteger("\n\t\tEnter a new student ID: ", true));
    s.setName(inputString("\n\t\tEnter the student's name: ", true));
    s.setMajor(inputString("\n\t\tEnter the student's major: ", true));
    s.setGPA(inputDouble("\n\t\tEnter a student's GPA (1.0..4.0): ", 0.0, 4.0));
    table.insertItem(s);
    cout << "\n\t\tInserted the new record." << endl;
}


//PreCondition: input hashTable 
//PostCondition: search student from the hashTable
void hashSearch(hashTable table)
{
    int ID = inputInteger("\n\t\tEnter a student ID to search: ", true);
    table.search(ID);
}


//PreCondition: input hashTable 
//PostCondition: remove student from the hashTable
void removeStudent(hashTable table)
{
    int ID = inputInteger("\n\t\tEnter a student ID to remove: ", true);
    table.removeItem(ID);
}
#endif