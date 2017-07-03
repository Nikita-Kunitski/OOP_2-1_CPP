#pragma once
#include<string>
using namespace std;

class Certification
{
protected:
	int day;
	int month;
	int year;
	string name;
	string last_name;
public:
	Certification();
	virtual void function_for_transform();
	void getData();
	void getAll_Name();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setName(string);
	void setLast_name(string);
	~Certification();
};