#include "stdafx.h"
#include "pasport.h"
#include <iostream>
#include <fstream>

using namespace std;

Pasport::Pasport() : series("BM")
{
	object_counter++;
	ifstream file ("database_pasport.txt");
	file>>number_series;
	file>>name;
	file>>day;
	file>>month;
	file>>year;
	file.close();
}
/*
void Pasport::Enter_date()
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

void Pasport::printDate()
{
	cout<<"\n\tDate:"<<date.day<<"."<<date.month<<"."<<date.year;
}

Date Pasport::getDate()
{
	return date;
}

int Pasport::getMoney()
{
	return 0;
}

Pasport::Pasport(int number_serie, string Name) : series("BM")
{
	object_counter++;
	number_series=number_serie;
	name=Name;
}

void Pasport::getAll_series() const
{
	cout<<"\n\tAll Series:"<<series<<number_series;
}

void Pasport::setNumber_series(int number_series)
{
	this->number_series=number_series;
}

void Pasport::getCounter()
{
	cout<<"\n\tCounter pasport's = "<<object_counter;
}

void Pasport::to_Console()
{
	cout<<"\t"<<typeid(this).name()<<":\n";
	this->getName();
	this->getAll_series();
}

Pasport::~Pasport()
{
	object_counter--;
}