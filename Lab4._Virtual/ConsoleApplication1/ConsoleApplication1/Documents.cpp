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

void Documents::getReceiver_Name()
{
	cout<<"\tReceiver name:"<<receiver_name<<endl;
}

void Documents::getSender_Name()
{
	cout<<"\tSender name:"<<sender_name<<endl;
}

Documents::~Documents()
{
}