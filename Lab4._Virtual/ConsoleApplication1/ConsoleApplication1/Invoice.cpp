#include "stdafx.h"
#include "invoice.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Invoice::Check::Check()
{
	ifstream file("database_check.txt");
	file>>summa;
	file>>adress;
	file.close();
}

void Invoice::to_Console()
{
	cout<<"\n\t"<<typeid(this).name()<<":"<<endl;
	cout<<"\tReceiver Name:"<<receiver_name<<endl;
	cout<<"\tSender Name:"<<sender_name<<endl;
	cout<<"\tProduct Name:"<<product_name<<endl;
	cout<<"\tQuantity:"<<quantity<<endl;
	cout<<"\tValue:"<<value<<endl;
}

void Invoice::Check::getSumma()
{
	cout<<"\tSumma: "<<this->summa<<endl;
}

void Invoice::Check::getAdress()
{
	cout<<"\tAdress: "<<this->adress<<endl;
}

void Invoice::Check::setAdress(string adress)
{
	this->adress=adress;
}

void Invoice::Check::setSumma(int summa)
{
	this->summa=summa;
}

void Invoice::Check::call_function(Invoice obj)
{
	cout<<"\tBase class method call"<<endl;
	obj.getProduct_Name();
}

Invoice::Check::~Check()
{}

void Invoice::call_inherit_function()
{
	cout<<endl;
	this->check->getAdress();
	cout<<endl;
}

Invoice::Invoice()
{
	check=new Check();
	string name_receiver, name_sender;
	ifstream file("database_invoice.txt");
	file>>product_name;
	file>>quantity;
	file>>value;
	file>>name_receiver;
	file>>name_sender;
	file.close();
	this->setReceiver_Name(name_receiver);
	this->setSender_Name(name_sender);
}

void Invoice::setProduct_Name(string name)
{
	this->product_name=name;
}

void Invoice::setQuantity(int quant)
{
	this->quantity=quant;
}

void Invoice::setValue(int val)
{
	this->value=val;
}

void Invoice::getValue()
{
	cout<<"\tValue: "<<this->value<<endl;
}

void Invoice::getProduct_Name()
{
	cout<<"\tProduct name: "<<this->product_name<<endl;
}

void Invoice::getQuantity()
{
	cout<<"\tQuantity: "<<this->quantity<<endl;
}

Invoice::~Invoice()
{
}