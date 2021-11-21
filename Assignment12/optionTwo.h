// optionTwo.h

#ifndef OPTION_TWO_LOCK
#define OPTION_TWO_LOCK

#include"DynamicString.h"
#include<iostream>
#include"input.h"
#include<cctype>

void A2(DynamicString& obj) {
	if (!obj.isEmpty())
		obj.clear();


	int size = inputInteger("\t\tEnter the size of the dynamic array: ", true);
	obj.setSize(size);
	obj.fillRandom();
	obj.sort();
}

void B2(DynamicString& obj) {
	std::string value = inputString("\t\tEnter a string element: ", true);
	obj.add(value);
	obj.sort();
}

void C2(DynamicString& obj) {

	if (obj.isEmpty()) {
		std::cout << "\t\tThe array is empty." << std::endl;
		return;
	}

	std::cout << "\t\t";
	obj.display();
}

int D2Sub1(DynamicString& obj) {
	std::cout << "\t\tRecursive serial search" << std::endl;
	std::cout << "\t\t" << std::string(100, char(205)) << std::endl;
	std::string searchFor = inputString("\t\tEnter a string element to search: ", true);
	return obj.serialSearch(searchFor, 0); // if serial search changed from top to bottom change 0 to obj.getSize();
}

int D2Sub2(DynamicString& obj) {
	std::cout << "\t\tBinary Search" << std::endl;
	std::cout << "\t\t" << std::string(100, char(205)) << std::endl;
	std::string searchFor = inputString("\t\tEnter a string element to search: ", true);
	return obj.callBinarySearch(searchFor); // if serial search changed from top to bottom change 0 to obj.getSize();
}

void D2(DynamicString& obj) {

	if (obj.isEmpty()) {
		std::cout << "\t\tThe array is empty." << std::endl;
		return;
	}

	do {
		char choice = inputChar("\t\tChoose search type (S)erial or (B)inary: ");
		std::string value;
		int index;

		switch (std::tolower(choice)) {
		case 's': index = D2Sub1(obj); break;
		case 'b': index = D2Sub2(obj); break;
		default: std::cout << "\t\tERROR: ONLY 'S' OR 'B' ALLOWED\n" << std::endl; continue;
		}

		if (index == -1) {
			std::cout << "\t\t\"" << value << "\" is not found in the unsorted array." << std::endl;
			break;
		}
		else {
			std::cout << "\t\t\"" << value << "\" is found at index " << index << " from the unsorted array." << std::endl;
			break;
		}
	} while (true);
}

void E2(DynamicString& obj) {
	obj.clear();
	std::cout << "\t\tElements from the array have been cleared/deleted." << std::endl;
}

#endif