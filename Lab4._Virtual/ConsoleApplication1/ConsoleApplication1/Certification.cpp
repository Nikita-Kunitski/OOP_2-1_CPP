#include "stdafx.h"
#include "certification.h"
#include <iostream>
#include <fstream>
using namespace std;

Certification::Certification()
{
	ifstream file("database_certification");	
	file>>day;
	file>>month;
	file>>year;
	file>>name;
	file>>last_name;
	file.close();
}

void Certification::function_for_transform()
{}

void Certification::getData()
{
	cout<<"\tDate:"<<this->day<<"."<<this->month<<"."<<this->year;
}

void Certification::getAll_Name()
{
	cout<<"\tAll name:"<<name<<" "<<this->last_name<<endl;
}

void Certification::setDay(int day)
{
	this->day=day;
}

void Certification::setMonth(int month)
{
	this->month=month;
}

void Certification::setYear(int year)
{
	this->year=year;
}

void Certification::setName(string name)
{
	this->name=name;
}

void Certification::setLast_name(string last_name)
{
	this->last_name=last_name;
}

Certification::~Certification()
{
}
