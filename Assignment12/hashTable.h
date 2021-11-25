#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class hashTable
{
    int size;
    vector<student>* hashList;

public:

    //PreCondition: NA
    //PostCondition: default constructor
    hashTable(int newSize=0)
    {
        this->size = newSize;
        hashList = new vector<student>[size];
    }

    //PreCondition: input newSize
    //PostCondition: set new value for size and size of hashList
    void setSize(int newSize)
    {
        this->size = newSize;
        hashList = new vector<student>[size];
    }

    //PreCondition: input x
    //PostCondition: return index of x
    int hashFunction(int x) 
    {
        return (x % size);
    }

    //PreCondition: input student
    //PostCondition: insert the student in to the hashList
    void insertItem(student s)
    {
        int index = hashFunction(s.getID());
        hashList[index].push_back(s);
    }

    //PreCondition: input x
    //PostCondition: remove the student from the hashList
    void removeItem(int x)
    {
        if (size == 0)
            cout << "\n\t\tERROR: ID cannot be found." << endl;
        else
        {
            int i = hashFunction(x);
            for (int j = 0; j < hashList[i].size(); j++)
            {
                if (hashList[i][j].getID() == x)
                {
                    hashList[i].erase(hashList[i].begin() + j);
                    cout << "\n\t\tStudent record index #" << i << " with ID: " << x << " has been removed." << endl;
                    return;
                }
            }
            cout << "\n\t\tERROR: ID cannot be found." << endl;
        }
    }

    //PreCondition: input x
    //PostCondition: return index of x
    int getIndex(int x) 
    {
        return hashFunction(x);
    }


    //PreCondition: NA
    //PostCondition: return size of the data in the hashlist
    int getSize() const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < hashList[i].size(); j++)
                count++;
        return count;
    }

    //PreCondition: input x
    //PostCondition: search x from the hashList
    void search(int x)
    {
        if (size == 0)
            cout << "\n\t\tERROR: ID cannot be found." << endl;
        else
        {
            int count = 0;
            int i = hashFunction(x);
            for (int j = 0; j < hashList[i].size(); j++)
            {
                if (hashList[i][j].getID() == x)
                {
                    count++;
                    cout << "\n\t\tStudent record found at index #" << i << endl;
                    cout << "\t\t\tStudent ID: " << hashList[i][j].getID() << endl;
                    cout << "\t\t\tName      : " << hashList[i][j].getName() << endl;
                    cout << "\t\t\tMajor     : " << hashList[i][j].getMajor() << endl;
                    cout << "\t\t\tGPA       : " << hashList[i][j].getGPA() << endl;
                }
            }
            if (count == 0)
                cout << "\n\t\tERROR: ID cannot be found." << endl;
        }
    }


    //PreCondition: NA
    //PostCondition: display all data from the hashList
    void display()
    {
        if (size == 0)
            cout << "\n\t\tERROR: No record found." << endl;
        else
        {
            cout << endl;
            for (int i = 0; i < size; i++)
            {
                vector<student>::iterator it;
                for (it = hashList[i].begin(); it != hashList[i].end(); ++it)
                    cout << "\t\t[" << setw(2) << right << i << "] - " << *it << endl;
            }
        }
    }

    //PreCondition: NA
    //PostCondition: clear all data from the hashList
    void clear()
    {
        for (int i = 0; i < size; i++)
            hashList[i].clear();
    }
};

