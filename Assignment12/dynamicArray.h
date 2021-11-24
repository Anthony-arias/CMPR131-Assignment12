// optionOne.h

#ifndef OPTION_ONE_LOCK
#define OPTION_ONE_LOCK
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "input.h"
using namespace std;

void initArray(vector<string>& array, bool isSort)
{
	srand(time(0));
	if (array.size() > 0)
		array.clear();
	int size = inputInteger("\n\t\tEnter the size of the dynamic array: ", true);
	for (int i = 0; i < size; i++)
	{
		string element = "str#" + to_string((rand() % size));
		array.push_back(element);
	}
	cout << "\n\t\tRandom elements have been populated into the array." << endl;
	if (isSort)
		sort(array.begin(), array.end());
}

void push(vector<string>& array, bool isSort)
{
	string element = inputString("\n\t\tEnter a string element: ", false);
	array.push_back(element);
	cout << "\n\t\tElement " << char(34) << element << char(34) << " has been added to the array." << endl;
	if (isSort)
		sort(array.begin(), array.end());
}

void display(vector<string> array)
{
	if (array.size() == 0)
		cout << "\n\t\tThe array is empty." << endl;
	else
	{
		cout << "\n\t\t";
		for (int i = 0; i < array.size(); i++)
			cout << array[i] << " ";
	}
}

void serialSearch(vector<string>array, string element, int i, int &location)
{
	if (i == array.size())
		return;
	if (array[i] == element)
		location = i;
	else
	{
		i++;
		serialSearch(array, element, i++, location);
	}
}


void binarySearch(vector<string>array, string element, int left, int right, int &location)
{
	int middle;
	if (right == 0)
		return;
	else
	{
		middle = left + right / 2;
		if (element == array[middle])
			location = middle;
		else
		{
			if (element < array[middle])
			{
				right = right / 2;
				binarySearch(array, element, left, right, location);
			}
			else
			{
				left = middle + 1;
				right = (right - 1) / 2;
				binarySearch(array, element, left, right, location);
			}
		}
	}
}

void search(vector<string>array, bool isSort)
{
	if (array.size() == 0)
		cout << "\n\t\tThe array is empty." << endl;
	else
	{
		int location = -1;
		char choice = inputChar("\n\t\tChoose search type (S)Serial or (B)Binary: ", 'S', 'B');
		if (toupper(choice) == 'S')
		{
			cout << "\n\t\tRecursive serial search" << endl;
			cout << "\t\t" + string(40, char(196)) << endl;
			string element = inputString("\n\t\tEnter a string element to search: ", false);
			serialSearch(array, element, 0, location);
			if (isSort)
			{
				if (location == -1)
					cout << "\n\t\t" << char(34) << element << char(34) << " is not found in the sorted array." << endl;
				else
					cout << "\n\t\t" << char(34) << element << char(34) << " is found at index "
					<< location << " from the sorted array." << endl;
			}
			else
			{
				if (location == -1)
					cout << "\n\t\t" << char(34) << element << char(34) << " is not found in the unsorted array." << endl;
				else
					cout << "\n\t\t" << char(34) << element << char(34) << " is found at index "
					<< location << " from the unsorted array." << endl;
			}
		}
		else
		{
			cout << "\n\t\tRecursive binary search" << endl;
			cout << "\t\t" + string(40, char(196)) << endl;
			string element = inputString("\n\t\tEnter a string element to search: ", false);
			int size = array.size();
			binarySearch(array, element, 0, size, location);
			if (isSort)
			{
				if (location == -1)
					cout << "\n\t\t" << char(34) << element << char(34) << " is not found in the sorted array." << endl;
				else
					cout << "\n\t\t" << char(34) << element << char(34) << " is found at index "
					<< location << " from the sorted array." << endl;
			}
			else
			{
				if (location == -1)
					cout << "\n\t\t" << char(34) << element << char(34) << " is not found in the unsorted array." << endl;
				else
					cout << "\n\t\t" << char(34) << element << char(34) << " is found at index "
					<< location << " from the unsorted array." << endl;
			}
		}
	}
}

void clearArray(vector<string> &array)
{
	if (array.size() == 0)
		cout << "\n\t\tThe array is empty." << endl;
	else
	{
		array.clear();
		cout << "\n\t\tElements from the array have been cleared/deleted.";
	}
}
#endif