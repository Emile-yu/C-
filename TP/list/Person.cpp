#include <iostream>
#include "Person.h"
using namespace std;

Person::Person(string _name, string _phone) {
	cout<<"Person"<<endl;
	name = _name;
	phone = _phone;
}

Person& Person::operator=(Person &person) {
	if(this != &person) {
		this->name = person.name;
		this->phone = person.phone;
	}
	return *this;
}

bool Person::operator==(Person &person) {
	if(this->name == person.name && this->phone == person.phone) {
		return true;
	}
	return false;

}

ostream& operator<<(ostream& o, const Person& p) {
	o<<p.name<<"----"<<p.phone<<endl;
	return o;
}