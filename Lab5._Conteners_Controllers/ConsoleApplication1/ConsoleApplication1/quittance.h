#pragma once
#include "documents.h"
#include <string>

using namespace std;

class Quittance : public Documents
{
	protected:
		string product_name;
	public:
		Quittance();
		~Quittance();
		void setMoney(int);
		void printDate();
		void Enter_date();
		int getMoney();
		void getProduct_Name();
		void to_Console();
		string getName();
		Date getDate();
};