#pragma once

#include <iostream>
using namespace std;

class student
{
private:
	int ID;
	string name;
	string major;
	double GPA;

public:
	//default constructor
	student() : ID(0), name("unknown"), major("unknown"), GPA(0.0)
	{}
 
	//mutator 
	void setID(int newID)
	{
		ID = newID;
	}

	void setName(string newName)
	{
		name = newName;
	}

	//mutator 
	void setMajor(string newMajor)
	{
		major = newMajor;
	}

	//mutator 
	void setGPA(double newGPA)
	{
		GPA = newGPA;
	}

	int getID() const
	{
		return ID;
	}

	string getName() const
	{
		return name;
	}


	string getMajor() const
	{
		return major;
	}

	double getGPA() const
	{
		return GPA;
	}
	//overloading operator <<
	friend ostream& operator <<(ostream& outs, const student& obj)
	{
		outs << obj.ID << ", " << obj.name << ", " << obj.major << ", " << obj.GPA;
		return outs;
	}

	//overloading operator == 
	friend bool operator ==(const student& obj1, const student& obj2)
	{
		if ((obj1.GPA == obj2.GPA) && (obj1.major == obj2.major) && (obj1.name == obj2.name) && (obj1.ID == obj2.ID))
			return true;
		else
			return false;
	}

};