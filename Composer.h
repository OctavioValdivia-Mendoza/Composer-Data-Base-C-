#pragma once
#ifndef COMPOSER_H
#define COMPOSER_H
#include <iostream>
using namespace std;

class composer {
private:
	string name;
	int date;
public:
	//Recieves: nothing
	//Returns: nothing
	composer();
	//recieves a string of composer and year
	//returns nothing
	// it is a  parameterized constructor for the composer class
	composer(string name, int year);
	//recieves nothing
	//returns a string of composer name
	string getName() const;
	//recieves nothing
	//returns int of death date
	int getDate() const;
	//recieves string of composer name
	//returns nothing
	//sets the name of the composer object to the value passed as argument.
	void setName(string name);
	//recieves int of death date
	//returns nothing
	//setse dates of death of the composer object to the value passed as argument.
	void setDate(int date);
	// recieves a const reference to another composer object
	// returns a boolean value indicating whether the current composer object is greater than the composer object passed
	bool operator>(const composer&) const;
	// recieves a const reference to another composer object
	// returns a boolean value indicating whether the two composer objects are equal in terms of their names.
	bool operator==(const composer&) const;
	// recieves a reference to an output stream object, and a const reference to a composer object
	// returns  a reference to an output stream object
	friend ostream& operator<<(ostream&, const composer&);
};

#endif
