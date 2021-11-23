// optionThree.h

#ifndef OPTION_THREE_LOCK
#define OPTION_THREE_LOCK

#include"DynamicString.h"
#include"input.h"
#include<fstream>
#include<iostream>
#include<string>

int hashID(int id) {
	return id % 10;
}

void A3(DynamicString &obj) {
	int size = inputInteger("\tEnter a number of read-in records: ", 1, 40);
	std::ifstream source;
	obj.setSize(size);

	while (true) {
		string s;
		source.open("Students.dat");

		if (!source.fail()) break;

		cout << "open failed, try again" << endl;
		source.clear();
		return;
	}

	/*
	* The functions gets the id of the student. First it checks if the id gathered is under  40(the array size) and if it is
	* then it inputs that line into that indexee.If not, then it "hashes" it by calling the hashID function which returns the 
	* remainder of id % 10. if that indexee is already taken, it then adds 1 each time, checking the next indexee to see if it
	* is taken, if it is not then it inputs the line into that index. 
	* 
	* Basically it applies open address indexing.
	* 
	* There needs to be a fix regarding multiple of the same ID's being placed, no double entrees should be allowed.
	*/
	while (true) {
		string line;
		getline(source, line); // can use >> and other things
		if (source.fail()) break; // not "failure", just end of file

		int commaAt = line.find(",");
		std::string idStr = line.substr(0, commaAt);
		int idNum = stoi(idStr);

		if (idNum < 40 && obj.at(idNum) == "") {
			obj.addAt(line, idNum);
			continue;
		}

		int targetIndex = hashID(idNum);

		if (obj.at(hashID(targetIndex)) == "") 
			obj.addAt(line, hashID(targetIndex));
		else {
			int count = 1;
			while (true) {
				if (obj.at(hashID(targetIndex) + count) != "") {
					std::cout << "in a3 top count: " << count << "targetIndex = " << targetIndex << std::endl;
					std::cout << obj.at(hashID(targetIndex) + count) << std::endl;
					count++;
					if (count == (size - 1))
						count = 0;
				}
				else {
					obj.addAt(line, hashID(targetIndex) + count);
					std::cout << "in a3 bottom count: " << count << std::endl;
					break;
				}
			}
		}
	}

	source.close();
}

void displayStudent(std::string student) {

}

void B3(DynamicString obj) {

	//int targetID = inputInteger("\n\t\tEnter a student ID to search: " true);

	//if (targetID < 40 && obj.at(targetID) != "") {
	//	std::cout << "\n\nStudent record found at index #" << targetID << std::endl;
	//	displayStudent(obj.at(targetID));


	//}

	//int targetIndex = hashID(idNum);

	//if (obj.at(hashID(targetIndex)) == "")
	//	obj.addAt(line, hashID(targetIndex));
}

void C3(DynamicString obj) {

}

void D3(DynamicString obj) {

}

void E3(DynamicString &obj) {
	for (int i = 0; i < obj.getSize(); i++) {
		if (obj.at(i) == "")
			continue;

		std::cout << "[" << i << "] - " << obj.at(i) << std::endl;
	}
}

#endif