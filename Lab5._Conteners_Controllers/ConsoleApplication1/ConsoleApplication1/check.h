#pragma once
#include <string>
#include <iostream>
#include "invoice.h"

using namespace std;

class Check:public Invoice
		{
		protected:
			string name;
			string adress;
			public:
				Date getDate();
				Check();
				void Enter_date();
				void printName();
				void printDate();
				int getMoney();
				string getName();
				void setMoney(int);
				void setAdress(string);
				void to_Console();
				~Check();
		};