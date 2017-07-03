#include "stdafx.h"
#include "documents.h"
#include <iostream>
#include <string>
#include <fstream>



using namespace std;

Documents::Documents()
{
	ifstream file("database_documents.txt");
	file>>receiver_name;
	file>>sender_name;
	file.close();
}


void Documents::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}
//имя получателя
void Documents::setReceiver_Name(string name)
{
	this->receiver_name=name;
}	 
//имя отправителя
void Documents::setSender_Name(string name)
{
	this->sender_name=name;
}

void Documents::printMoney()
{
	cout<<"\n\tMoney:"<<this->money;
}

void Documents::getReceiver_Name()
{
	cout<<"\n\tReceiver name:"<<receiver_name;
}

void Documents::getSender_Name()
{
	cout<<"\n\tSender name:"<<sender_name;
}

Documents::~Documents()
{
}