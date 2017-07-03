#include "stdafx.h"
#include "certification.h"
#include <iostream>
#include <fstream>
using namespace std;

Certification::Certification()
{
	ifstream file("database_certification.txt");	
	file>>day;
	file>>month;
	file>>year;
	file>>name;
	file.close();
}

void Certification::function_for_transform()
{}

Date Certification::getDate()
{
	return date;
}

void Certification::to_Console()
{
	cout<<"\n\t"<<typeid(this).name()<<":"<<endl;
	cout<<"\tDate of Birth: "<<day<<"."<<month<<"."<<year<<endl;
	cout<<"\tName: "<<name<<endl;
}

void Certification::Enter_date()
{
	cout<<"\n\n"<<typeid(this).name();
	cout<<"\nName:"<<this->name;
	cout<<"\nEnter day:";
	cin>>date.day;
	cout<<"Enter month:";
	cin>>date.month;
	cout<<"Enter year:";
	cin>>date.year;
}

void Certification::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}

string Certification::getName()
{
	return name;
}

int Certification::getMoney()
{
	return 0;
}

void Certification::setDay(unsigned int day)
{
	this->day=day;
}

void Certification::setMonth(unsigned int month)
{
	this->month=month;
}

void Certification::setYear(unsigned int year)
{
	this->year=year;
}

void Certification::setName(string name)
{
	this->name=name;
}

Certification::~Certification()
{
}
