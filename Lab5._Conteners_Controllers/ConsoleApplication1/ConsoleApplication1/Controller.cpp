#include "stdafx.h"
#include "invoice.h"
#include "quittance.h"
#include "check.h"
#include "controller.h"
#include <iostream>
using namespace std;
Accounting* Controller::getAccounting()
{
	return accounting;
}

void Controller::getSum()
{
	Accounting *account;
	int summa=0;
	account=accounting->getHead();
	while(account)
	{
		if(dynamic_cast<Quittance*>(account) ||
				dynamic_cast<Invoice*>(account) || 
					dynamic_cast<Check*>(account))
		summa+=account->getMoney();
		account=account->getNext();
	}
	cout<<"\n\n\tSumma all's documents:"<<summa<<endl;
}

void Controller::getChecks()
{
	Accounting *account;
	int counter=0;
	account=accounting->getHead();
		while (account)
		{
			if(dynamic_cast<Check*>(account))
			{
				counter++;			
			}
			account=account->getNext();
		}
		cout<<"\n\n\tAll checks:"<<counter;
}

void Controller::getDocuments_by_Date(Date begin_date, Date end_date)
{
	Accounting *account;
	account=accounting->getHead();
	while(account)
	{
		if(account->getDate().year>begin_date.year && account->getDate().year<end_date.year)
		{
					account->to_Console();
		}
		if(account->getDate().year==begin_date.year)
			{
				if(account->getDate().month>begin_date.month)
					account->to_Console();
				else if(account->getDate().month==begin_date.month)
						{
							if(account->getDate().day>=begin_date.day)
								account->to_Console();
						}
			}
		if(account->getDate().year==end_date.year)
			{
				if(account->getDate().month < end_date.month)
					account->to_Console();
				else if(account->getDate().month == end_date.month)
					{
						if(account->getDate().day<=end_date.day)
							account->to_Console();
					}
			}
		account=account->getNext();
	}
}