#pragma once
#include <string>
#include <iostream>

using namespace std;

class Documents
{
	protected:
		string receiver_name;//имя получателя
		string sender_name;//имя отправителя
	public:
		Documents();
		~Documents();
		void setReceiver_Name(string);
		void setSender_Name(string);
		void getReceiver_Name();
		void getSender_Name();
		virtual void to_Console()=0;
};
