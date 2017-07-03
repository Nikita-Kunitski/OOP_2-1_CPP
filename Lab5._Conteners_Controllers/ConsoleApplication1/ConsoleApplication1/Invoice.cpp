#include "stdafx.h"
#include "invoice.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
Date Invoice::getDate()
{
	return date;
}
/*
void Invoice::Enter_date()
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

void Invoice::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}

void Invoice::to_Console()
{
	cout<<"\t"<<typeid(this).name()<<":"<<endl;
	this->getReceiver_Name();
	this->getSender_Name();
	this->getProduct_Name();
	this->getQuantity();
	this->printMoney();
	this->printDate();
}

string Invoice::getName()
{
	return receiver_name;
}

void Invoice::getAdress()
{
	cout<<"\n\tAdress: "<< adress;
}

Invoice::Invoice()
{
	ifstream file("database_invoice.txt");
	file>>product_name;
	file>>quantity;
	file>>money;
	file>>receiver_name;
	file>>sender_name;
	file>>adress;
	file>>date.day;
	file>>date.month;
	file>>date.year;
	file.close();
}

void Invoice::setProduct_Name(string name)
{
	this->product_name=name;
}

void Invoice::setQuantity(int quant)
{
	this->quantity=quant;
}

void Invoice::setMoney(int mon)
{
	money=mon;
}

int Invoice::getMoney()
{
	return money;
}

void Invoice::getProduct_Name()
{
	cout<<"\n\tProduct name: "<<this->product_name;
}

void Invoice::getQuantity()
{
	cout<<"\n\tQuantity: "<<this->quantity;
}

Invoice::~Invoice()
{
}