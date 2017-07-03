#pragma once
#include "accounting.h"
#include "controller.h"
#include<string>
using namespace std;

class Certification:public Accounting, public Controller
{
protected:
	int day;
	int month;
	int year;
	string name;
public:
	Certification();
	Date getDate();
	virtual void function_for_transform();
	string getName();
	void printDate();
	int getMoney();
	void Enter_date();
	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);
	void setName(string);
	void to_Console();
	~Certification();
};