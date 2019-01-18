#pragma once
#include<string>
using namespace std;

class ExceptionTP
{
private:
	string _message;
public:
	ExceptionTP(const string &message){_message=message;}

	virtual ~ExceptionTP(){};

	string getmessage() const{return _message;}
};
