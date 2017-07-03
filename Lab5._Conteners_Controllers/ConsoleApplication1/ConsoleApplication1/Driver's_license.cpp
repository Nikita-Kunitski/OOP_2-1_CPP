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
	file>>category;
	file.close();
}

Date Driver_license::getDate()
{
	return date;
}

int Driver_license::getMoney()
{
	return 0;
}
/*
void Driver_license::Enter_date()
{
	cout<<"\n\n"<<typeid(this).name();
	cout<<"\nName:"<<name;
	cout<<"\nEnter day:";
	cin>>date.day;
	cout<<"Enter month:";
	cin>>date.month;
	cout<<"Enter year:";
	cin>>date.year;
}*/

void Driver_license::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}

void Driver_license::getCategory()
{
	cout<<"\tCategory:"<<this->category;
}

void Driver_license::setCategory(string category)
{
	this->category=category;
}

void Driver_license::to_Console()
{
	cout<<"\t"<<typeid(this).name()<<":\n";
	this->getName();
	this->getCategory();
}

Driver_license::~Driver_license()
{
}