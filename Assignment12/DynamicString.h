// DynamicString.h
// A dynamic array of strings

#ifndef STRING_LOCK
#define STRING_LOCK

#include<string>
#include <iostream>
#include"assert.h"
#include"input.h"

class DynamicString {
private:
	std::string* myArr;
	int size;
	int capacity = 0;

	void setCapacity(int newCapacity) {

		if (newCapacity < 0)
			throw std::invalid_argument("setCapacity argument must be >= 0");

		if (newCapacity == 0) {
			if (size > 0)
				clear();

			capacity = newCapacity;
			return;
		}

		// Checking if downgrading, only copying up to capacity, deleting the rest
		if (newCapacity < size)
			size = newCapacity;

		std::string* newArray = new std::string[newCapacity];

		for (int i = 0; i < size; i++)
			newArray[i] = myArr[i];

		if (size > 0) {
			int tempS = size;
			clear();
			size = tempS;
		}

		myArr = newArray;
		capacity = newCapacity;
	}

	void copy(DynamicString obj) {
		clear();
		setSize(obj.getSize());
		for (int i = 0; i < obj.getSize(); i++) 
			myArr[i] = obj.at(i);
		
	}

public:
	DynamicString() {
		size = 0;
		setCapacity(2);
	}

	DynamicString(int newSize) {
		try {
			setCapacity(newSize + 5);
			setSize(newSize);
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
		}
	}

	DynamicString(DynamicString &dynamic) {
		copy(dynamic);
	}

	~DynamicString() {
		delete[] myArr;
	}

	std::string at(const int targetIndex) {
		if (targetIndex >= size)
			return "INVALID_INDEX";
		else
			return myArr[targetIndex];
	}

	// Precondition: NA
	// Postcondition: places object to the end of the array
	void add(const std::string object) {
		// reached maximum capacity, adding to capacity by 50%
		if (size >= capacity) {
			setCapacity(capacity + capacity / 2);
		}

		myArr[size] = object;
		size++;
	}

	// Precondition: newSize must be greater or equal to 0
	// Postcondition: sets size to newSize
	int setSize(const int newSize) {
		if (newSize < 0)
			throw std::invalid_argument("setSize(int) argument must be >= 0");
		else {
			if (capacity <= newSize) {
				setCapacity(newSize * 1.5);
				size = newSize;
			}
			else {
				clear();
				size = newSize;
			}
		}
	}

	// Precondition: NA
	// Postcondition: returns the size of the array
	int getSize() const {
		return size;
	}

	// Precondition: NA
	// Postcondition: allows the use of [] 
	const std::string operator[](int targetIndex) const {

		// checking if targetIndex is out of bounds
		if (targetIndex >= size)
			assert(targetIndex < size);

		return myArr[targetIndex];
	}

	// Precondition: NA
	// Postcondition: allows the use of [] as well as manipulation of the element in targetIndex
	std::string& operator[](int targetIndex) {
		return myArr[targetIndex];
	}

	// Precondition: NA
	// Postcondition: sets size to 0 and clears the array
	void clear() {
		size = 0;
		delete[] myArr;
	}

	// Precondition: NA
	// Postcondition: displays the elements in the array
	void display() const {
		for (int i = 0; i < size; i++)
			std::cout << myArr[i] << " ";
		std::cout << std::endl;
	}

	// Precondition: NA
	// Postcondition: fills the array with strings of "str#" + a random number between 0 and size
	void fillRandom() {
		for (int i = 0; i < size; i++) {
			myArr[i] = ("str#" + std::to_string(randomInt(0, size)));
		}
	}

	// Precondition: list should not be empty
	// Postcondition: sorts the array from least to greatest (selection sort)
	void sort()
	{
		if (isEmpty())
			return;

		for (int leftBagLocation = 0; leftBagLocation < size; ++leftBagLocation)
		{
			int smallestIndex = leftBagLocation;
			for (int search = leftBagLocation + 1; search < size; ++search)
				if (myArr[search] < myArr[smallestIndex])
					smallestIndex = search;

			std::string swapValue = myArr[leftBagLocation];
			myArr[leftBagLocation] = myArr[smallestIndex];
			myArr[smallestIndex] = swapValue;
		}
	}

	bool isEmpty() {
		return size == 0;
	}

	// Precondition: index must begin at 0
	// Postcondition: returns index of targetValue or else returns -1
	// NOTE: can change to index be originally be the size -1 and then subtract one each recursive call intil 0 is hit, then check if match
	int serialSearch(std::string targetValue, int index) const {
		// we are at the end of the array, the element at this indexee either matches or it doesn't
		if (index == (size - 1) && myArr[index] != targetValue)
			return -1;
		else if (index == (size - 1) && myArr[index] == targetValue)
			return index;

		if (targetValue == myArr[index])
			return index;
		else
			return serialSearch(targetValue, index + 1);
	}

	int callBinarySearch(std::string target) {
		return binarySearch(myArr, 0, size, target);
	}

	int binarySearch(std::string data[], int first, int thisSize, std::string target) {
		if (thisSize == 0) {
			return -1;
		}
		else {
			int middle = first + thisSize / 2;
			if (target == data[middle])
				return middle;
			else if (target < data[middle])
				return binarySearch(data, first, thisSize / 2, target);
			else if (target > data[middle])
				return binarySearch(data, middle + 1, (size - 1) / 2, target);
		}
	}

};


#endif