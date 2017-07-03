// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "token.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try{
	Expression object(250,10,'*');
	cout<<object.getNumber_1()<<endl;
	cout<<object.getOpreator()<<endl;
	object.result();
	}
	catch(Exeption_char exp)
	{
		exp.to_console();
	}
	return 0;
}

