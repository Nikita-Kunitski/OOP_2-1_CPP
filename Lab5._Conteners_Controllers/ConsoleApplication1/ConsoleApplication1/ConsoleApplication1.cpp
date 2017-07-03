
// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "controller.h"
#include "documents.h"
#include "quittance.h"
#include "invoice.h"
#include "pasport.h"
#include "printer.h"
#include "driver's_license.h"
#include "check.h"
#include <iostream>

using namespace std;

int Pasport::object_counter=0;

int _tmain(int argc, _TCHAR* argv[])
{
	int index=0;
	string name;
	Quittance *quittance=new Quittance;
	Invoice *invoice=new Invoice;
	Check *check=new Check;
	Certification *certification=new Certification;
	Pasport *pasport=new Pasport;
	Driver_license *driver_license=new Driver_license;
	Controller *controller=new Controller;
	Date begin_date, end_date;
	 do
	 {
		 cout<<"\n\tMenu:"<<endl;
		 cout<<"1-Add Quittance to list;"<<endl;
		 cout<<"2-Add Invoice to list;"<<endl;
		 cout<<"3-Add Check to list;"<<endl;
		 cout<<"4-Add Pasport to list;"<<endl;
		 cout<<"5-Add Certification to list;"<<endl;
		 cout<<"6-Delete element of list;"<<endl;
		 cout<<"7-Show all list to console;"<<endl;
		 cout<<"8-Show summa all's documents;"<<endl;
		 cout<<"9-Show all checks;"<<endl;
		 cout<<"10-Show all documents in period;"<<endl;
		 cout<<"11-Clear display;"<<endl;
		 cout<<"0-Exit"<<endl;
		 cin>>index;
		 switch (index)
		 {
		 case 1:
			 {
				 Quittance *quittance_1=new Quittance;
				quittance_1->add();
			 }
			 break;
		 case 2:{
			 Invoice *invoice_1=invoice;
					invoice_1->add();
				}
				break;
		 case 3:{
			 Check *check_1=new Check;
			 check_1->add();
				}break;

			 case 4:{
				 Pasport *pasport_1=new Pasport;
				 pasport_1=pasport;
				 pasport_1->add();
				}break;

				 case 5:{
					 Certification *certification_1=new Certification;
					 certification_1=certification;
					 certification_1->add();
				}break;

		 case 6:
			 {
				 cout<<"\nEnter name:";
				 cin>>name;
				 controller->getAccounting()->Delete(name);
			 }
		 case 7:
			 {
				 controller->getAccounting()->show_to_console();
			 }break;

		 case 8:
			 {
				 controller->getSum();
			 }break;
		 case 9:
			 {
				 controller->getChecks();
			 }break;
		 case 10:
			 {
				 cout<<"\nEnter date beginning of period (day): ";
				 cin>>begin_date.day;
				 cout<<"\nEnter date beginning of period (month): ";
				 cin>>begin_date.month;
				 cout<<"\nEnter date beginning of period (year): ";
				 cin>>begin_date.year;
				 cout<<"\nEnter date end of period (day): ";
				 cin>>end_date.day;
				 cout<<"\nEnter date end of period (month): ";
				 cin>>end_date.month;
				 cout<<"\nEnter date end of period (year): ";
				 cin>>end_date.year;
				 controller->getDocuments_by_Date(begin_date,end_date);
			 }break;

		 case 11:
			 {
			 system("cls");
			 }break;
		 }

	 }while(index!=0);

		
	return 0;
}

