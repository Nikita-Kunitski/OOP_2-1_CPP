#pragma once
#include "certification.h"
using namespace std;

class Pasport:public Certification
{
	protected:
		const char *series;
		int number_series;
		static int object_counter;
	public:
		Pasport();
		void printDate();
		void Enter_date();
		Date getDate();
		Pasport(int,string);
		void getAll_series() const;
		int getMoney();
		void getCounter();
		void setNumber_series(int);
		void to_Console();
		~Pasport();
};