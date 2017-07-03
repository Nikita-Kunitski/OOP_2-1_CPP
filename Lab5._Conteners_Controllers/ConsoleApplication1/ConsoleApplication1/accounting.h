#pragma once 
#include <string>
using namespace std;

struct Date
		{
			unsigned int day;
			unsigned int month;
			unsigned int year;
		};

class Accounting
{
protected:
	Accounting* next;
	Accounting* prev;
	static Accounting* head;
	static int element_counter;
	Date date;
public:
	Accounting *getHead();
	Accounting *getNext();
	Accounting *getPrev();
	void add();
	void show_to_console();
	virtual Date getDate()=0;
	virtual string getName()=0;
	virtual int getMoney()=0;
	virtual void printDate()=0;
	//virtual void Enter_date()=0;
	void Delete(string);
	virtual void to_Console()=0;
};