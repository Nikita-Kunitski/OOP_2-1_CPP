#include "stdafx.h"
#include <iostream>
#include "quittance.h"
#include <string>
#include <fstream>

using namespace std;

Date Quittance::getDate()
{
	return date;
}

void Quittance::to_Console()
{
	cout<<"\n\t"<<typeid(this).name()<<":\n";
	this->getReceiver_Name();
	this->getSender_Name();
	this->printMoney();
	this->printDate();
	this->getProduct_Name();
}
/*
void Quittance::Enter_date()
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

void Quittance::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}

Quittance::Quittance()
{
		ifstream file("database_quittance.txt");
		file>>money;
		file>>sender_name;
		file>>receiver_name;
		file>>product_name;
		file>>date.day;
		file>>date.month;
		file>>date.year;
		file.close();
}

void Quittance::getProduct_Name()
{
	cout<<"\n\tProduct name: "<<product_name;	
}

string Quittance::getName()
{
	return receiver_name;
}

void Quittance::setMoney(int Money)
{
	money=Money;
}

int Quittance::getMoney()
{
return money;
}

Quittance::~Quittance()
{
}

