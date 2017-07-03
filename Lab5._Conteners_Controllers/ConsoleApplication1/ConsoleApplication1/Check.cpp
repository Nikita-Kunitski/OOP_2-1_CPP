#include "stdafx.h"
#include "check.h"
#include <fstream>
#include <iostream>
#include <string>

Check::Check()
{
	ifstream file("database_check.txt");
	file>>money;
	file>>product_name;
	file>>adress;
	file>>name;
	file>>date.day;
	file>>date.month;
	file>>date.year;
	file.close();
}

void Check::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}
/*
void Check::Enter_date()
{
	cout<<"\n\n"<<typeid(this).name();
	this->getProduct_Name();
	cout<<"\nEnter day:";
	cin>>date.day;
	cout<<"Enter month:";
	cin>>date.month;
	cout<<"Enter year:";
	cin>>date.year;
}*/

void Check::to_Console()
{
	cout<<"\n\t"<<typeid(this).name()<<":\n";
	this->printName();
	this->printMoney();
	this->getProduct_Name();
	this->getAdress();
	this->printDate();
}

int Check::getMoney()
{
	return money;
}

void Check::printName()
{
	cout<<"\n\tName:"<<name;
}

void Check::setAdress(string adress)
{
	this->adress=adress;
}

void Check::setMoney(int mon)
{
	money=mon;
}

Date Check::getDate()
{
	return date;
}

string Check::getName()
{
	return name;
}

Check::~Check()
{}