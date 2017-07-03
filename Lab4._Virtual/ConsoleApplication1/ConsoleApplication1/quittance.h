#pragma once
#include "documents.h"


using namespace std;
typedef unsigned int ui;

class Quittance : public Documents
{
	public:
		Quittance();
		~Quittance();
		void setMoney();
		void getMoney();
		void to_Console();
protected:
	ui money;
};