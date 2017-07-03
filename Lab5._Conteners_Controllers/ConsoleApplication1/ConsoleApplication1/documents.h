#pragma once
#include <string>
#include <iostream>
#include "controller.h"
#include "accounting.h"
using namespace std;

/*struct Date
		{
			int day;
			int month;
			int year;
		};*/

class Documents: public Accounting, public Controller
{
	protected:
		string receiver_name;//имя получателя
		string sender_name;//имя отправителя
		/*int day;
		int month;
		int year;*/
		/*Date date;*/
		int money;
	public:
		virtual Date getDate()=0;
		Documents();
		~Documents();
		void printMoney();
		//virtual void Enter_date()=0;
		void printDate();
		void setReceiver_Name(string);
		void setSender_Name(string);
		void getReceiver_Name();
		void getSender_Name();
		virtual void to_Console()=0;
};
