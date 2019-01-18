#pragma once
#include <iostream>
using namespace std;
class Stage {
private :
	int _min;
	int _max;
	bool _evalue;
public:

	Stage():_min(4),_max(8),_evalue(false) {}

	Stage(int min,int max,bool evalue):_evalue(0) {
		setmax(max);
		setmin(min);
		setevalue(evalue);
	}

	int getmin() const { return _min;}

	void setmin(int min) {
		if(min>0 && min<=_min)
		{
			_min=min;
		}
	}

	int getmax() const { return _max;}

	void setmax(int max) {
		if(max>=_min)
		{
			_max=max;
		}

	}

	bool getevalue() const {return _evalue;}

	void setevalue(bool evalue) {_evalue=evalue;}

	bool egal (const Stage &s)
	{
		return ((s.getmin()==_min) && (s.getmax()==_max) && (s.getevalue()==_evalue));
	}
};
extern ostream & operator<<(ostream &o,const Stage &s);