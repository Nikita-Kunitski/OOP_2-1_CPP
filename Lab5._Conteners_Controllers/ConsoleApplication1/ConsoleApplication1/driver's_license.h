#pragma once
#include "pasport.h"
using namespace std;

class Driver_license: protected Pasport
{
private:
	string category;
public:
	Driver_license();
	void getCategory();
	int getMoney();
	void printDate();
	void Enter_date();
	Date getDate();
	void setCategory(string);
	void to_Console();
	~Driver_license();
};