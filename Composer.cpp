#ifndef COMPOSER_CPP
#define COMPOSER_CPP
#include "Composer.h"
#include <iostream>
using namespace std;

composer::composer() {
	name = "";
	date = 0;
}

composer::composer(string name, int date) {
	this->name = name;
	this->date = date;
}

void composer::setName(string name) {
	this->name = name;
}

string composer::getName() const {
	return name;
}

void composer::setDate(int date) {
	this->date = date;
}

int composer::getDate() const {
	return date;
}
bool composer::operator==(const composer& right) const {
	return (this->name == right.name);
}

bool composer::operator>(const composer& right) const {
	return (this->date < right.date);
}


ostream& operator<<(ostream& cout, const composer& right) {
	cout << right.name << " - " << right.date;
	return cout;
}
#endif;