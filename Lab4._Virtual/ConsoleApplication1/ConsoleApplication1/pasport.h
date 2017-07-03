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
		Pasport(int,string, string);
		void getAll_series() const;
		void getAll_Name() const;
		void getCounter();
		void setNumber_series(int);
		~Pasport();
};