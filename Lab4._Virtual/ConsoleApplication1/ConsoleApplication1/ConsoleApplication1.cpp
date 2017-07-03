
// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "documents.h"
#include "quittance.h"
#include "invoice.h"
#include "pasport.h"
#include "printer.h"
#include "driver's_license.h"
#include <iostream>

using namespace std;

int Pasport::object_counter=0;

int _tmain(int argc, _TCHAR* argv[])
{
	Driver_license object_1;
	cout<<"\n\nDemonstration class 'Driver_license':\n\n";
	object_1.getAll_Name();
	object_1.getCategory();

	Quittance object_2;
	cout<<"\n\nDemonstration class 'Quittance':\n\n";
	object_2.getReceiver_Name();
	object_2.getSender_Name();
	object_2.getMoney();

	Invoice object_3;
	cout<<"\n\nDemonstration class 'Invoice':\n\n";
	object_3.getReceiver_Name();
	object_3.getSender_Name();
	object_3.getProduct_Name();
	object_3.getQuantity();
	object_3.getValue();
	object_3.call_inherit_function();

		Invoice::Check object_4;
		cout<<"\n\nDemonstration inherit class 'Check':\n\n";
		object_4.getAdress();
		object_4.getSumma();
		object_4.call_function(object_3);
		
		Pasport object_5;
		cout<<"\n\nDemonstration class 'Pasport':\n\n";
		object_5.getAll_Name();
		object_5.getAll_series();
		object_5.getCounter();

		Pasport object_6(354154,"Vova","Polyakov");
			object_6.getAll_Name();
			object_6.getAll_series();
			object_6.getCounter();

			/*-------------------print-------------------*/
			cout<<"\n\n************TYPEID**************";
			cout<<"\n\t";
			Documents *Object_7=new Invoice;
			Quittance *Object_8=new Quittance;
			Printer print;
			print.IAmPrinting(Object_7);
			cout<<"\n\n\t";
			print.IAmPrinting(Object_8);
			/*-------------------print-------------------*/

			/*---------------------------transformation---------------------------*/
				cout<<"\n\n\t*****dynamic_cast : static_cast : const_cast*****";
				cout<<"\n\tdynamic_cast(Pasport->Certification):\n";

				Pasport *ppasp=new Pasport;
				Certification *pcert=dynamic_cast<Pasport*>(ppasp);
				cout<<"\t"<<typeid(ppasp).name()<<endl;

				cout<<"\n\n\t *******transformation static_cast*******";
				double arr=51.2156;
				int transf=static_cast<double>(arr);
				cout<<"\n\n\tarr="<<arr<<" (double->int) 'arr->transf'";
				cout<<"\n\ttransf(typeid):"<<typeid(transf).name()<<endl;
				cout<<"\ttransf="<<transf<<endl;

				cout<<"\n\n\t *******transformation const_cast*******";
				const double* constant_variable=&arr;
				double *constant_variable_2;
				cout<<"\n\tconstant_variable="<<*constant_variable<<"("<<typeid(constant_variable).name()<<")";
				constant_variable_2=const_cast<double*>(constant_variable);
				*constant_variable_2=100;
				cout<<"\n\tconstant_variable="<<*constant_variable<<"\n";
	return 0;
}

