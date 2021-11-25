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

	//PreCondition: NA
	//PostCondition: default constructor
	student() : ID(0), name("unknown"), major("unknown"), GPA(0.0)
	{}
 
	//PreCondition: input newID
	//PostCondition: set new value for ID
	void setID(int newID)
	{
		ID = newID;
	}

	//PreCondition: input newName
	//PostCondition: set new value for name
	void setName(string newName)
	{
		name = newName;
	}

	//PreCondition: input newMajor
	//PostCondition: set new value for major
	void setMajor(string newMajor)
	{
		major = newMajor;
	}


	//PreCondition: input newGPA
	//PostCondition: set new value for GPA 
	void setGPA(double newGPA)
	{
		GPA = newGPA;
	}

	//PreCondition: NA
	//PostCondition: return ID
	int getID() const
	{
		return ID;
	}


	//PreCondition: NA
	//PostCondition: return name
	string getName() const
	{
		return name;
	}


	//PreCondition: NA
	//PostCondition: return major
	string getMajor() const
	{
		return major;
	}


	//PreCondition: NA
	//PostCondition: return GPA
	double getGPA() const
	{
		return GPA;
	}


	//PreCondition: NA
	//PostCondition: overloading operator <<
	friend ostream& operator <<(ostream& outs, const student& obj)
	{
		outs << obj.ID << ", " << obj.name << ", " << obj.major << ", " << obj.GPA;
		return outs;
	}


	//PreCondition: NA
	//PostCondition: overloading operator ==
	friend bool operator ==(const student& obj1, const student& obj2)
	{
		if ((obj1.GPA == obj2.GPA) && (obj1.major == obj2.major) && (obj1.name == obj2.name) && (obj1.ID == obj2.ID))
			return true;
		else
			return false;
	}

};