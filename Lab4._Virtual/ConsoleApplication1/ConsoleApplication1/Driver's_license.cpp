#include "stdafx.h"
#include "driver's_license.h"
#include <fstream>
#include <iostream>
using namespace std;

Driver_license::Driver_license()
{
	ifstream file("database_driver_license.txt");
	file>>day;
	file>>month;
	file>>year;
	file>>name;
	file>>last_name;
	file>>category;
	file.close();
}

void Driver_license::getCategory()
{
	cout<<"\tCategory:"<<this->category;
}

void Driver_license::getAll_Name()
{
	this->Certification::getAll_Name();
}

void Driver_license::setCategory(string category)
{
	this->category=category;
}

Driver_license::~Driver_license()
{
}