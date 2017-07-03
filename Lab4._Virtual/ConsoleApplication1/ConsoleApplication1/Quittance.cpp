#include "stdafx.h"
#include <iostream>
#include "quittance.h"
#include <string>
#include <fstream>

using namespace std;

void Quittance::to_Console()
{
	cout<<"\n\t"<<typeid(this).name()<<":\n";
	cout<<"\tReceiver Name:"<<receiver_name<<endl;
	cout<<"\tSender Name:"<<sender_name<<endl;
	cout<<"\tMoney in quittance:"<<money<<endl;
}

Quittance::Quittance()
{
	string name_receiver, name_sender;
		ifstream file("database_quittance.txt");
		file>>money;
		file>>name_sender;
		file>>name_receiver;
		file.close();
	this->setReceiver_Name(name_receiver);
	this->setSender_Name(name_sender);
}

void Quittance::setMoney()
{
	cout<<"Enter money: ";
	cin>>this->money;
}

void Quittance::getMoney()
{
	cout<<"\tMoney: "<<this->money;
}

Quittance::~Quittance()
{
}

