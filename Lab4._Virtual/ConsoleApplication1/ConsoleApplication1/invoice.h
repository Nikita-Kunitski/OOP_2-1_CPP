#pragma once 
#include "documents.h"
#include <string>
//накладная
using namespace std;

class Invoice: public Documents
{
	private:
		string product_name;
		int value;
		int quantity;
		
	public:
		class Check
		{
		private:
			int summa;
			string adress;
			public:
				Check();
				void getSumma();
				void getAdress();
				void setSumma(int);
				void setAdress(string);
				void call_function(Invoice);
				~Check();
		};
		Check *check;
		Invoice();
		void setProduct_Name(string);
		void setQuantity(int);
		void setValue(int);
		void getValue();
		void call_inherit_function();
		void getProduct_Name();
		void getQuantity();
		void to_Console();
		~Invoice();
};