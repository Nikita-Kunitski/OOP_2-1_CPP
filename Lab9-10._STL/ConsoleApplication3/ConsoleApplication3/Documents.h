#pragma once
#include <iostream>
#include <string>
using namespace std;
class Documents
{
protected:
	string name;
public:
	Documents(string);
	string getName();
	void setName(string);
	friend std::ostream& operator << (std::ostream&,Documents*);
	friend std::ostream& operator<<(std::ostream&, Documents&);
	~Documents(){cout<<"Documents...";};
};