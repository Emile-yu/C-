#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	Person(string _name="", string _phone="");
	~Person() {cout<<"~Person"<<endl;}
	void setName(const string _name) {name = _name;}
	void setPhone(const string _phone) {phone = _phone;}
	bool operator==(Person &person);
	Person& operator=(Person &person);
	friend ostream& operator<<(ostream& o, const Person& p);
private:
	string name;
	string phone;
};
#endif