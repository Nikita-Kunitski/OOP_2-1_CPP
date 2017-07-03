#pragma once 
#include "documents.h"
#include <string>
//накладная
using namespace std;

typedef unsigned int ui;

class Invoice: public Documents
{
	protected:
		string product_name;
		int quantity;
		string adress;
	public:
		Invoice();
		void Enter_date();
		Date getDate();
		void setProduct_Name(string);
		void setQuantity(int);
		void setMoney(int);
		string getName();
		int getMoney();
		void printDate();
		void getAdress();
		void getProduct_Name();
		void getQuantity();
		void to_Console();
		~Invoice();
};