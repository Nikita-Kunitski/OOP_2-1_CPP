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
	void getAll_Name();
	void setCategory(string);
	~Driver_license();
};