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
	file>>last_name;
	file.close();
}

Pasport::Pasport(int number_serie, string Name, string Last_name) : series("BM")
{
	object_counter++;
	number_series=number_serie;
	name=Name;
	last_name=Last_name;
}

void Pasport::getAll_series() const
{
	cout<<"\tAll Series:"<<series<<number_series<<endl;
}

void Pasport::setNumber_series(int number_series)
{
	this->number_series=number_series;
}

void Pasport::getAll_Name() const
{
	cout<<"\tAll Name:"<< name<<" "<<last_name<<endl;
}

void Pasport::getCounter()
{
	cout<<"\tCounter pasport's = "<<object_counter<<endl;
}

Pasport::~Pasport()
{
	object_counter--;
}