#include "stdafx.h"
#include "token.h"
#include <iostream>
using namespace std;

Expression::Expression()
{
	var_1=0;
	var_2=0;
	operation='*';
}

Expression::Expression(int v_1, int v_2, char operation_)
{
	var_1=v_1;
	var_2=v_2;
	operation=operation_;
	if(operation!='*' && operation !='/')
		throw Exeption_char();
}

char Expression::getOpreator()
{
	return operation;
}

int Expression::getNumber_1()
{
	return var_1;
}

int Expression::getNumber_2()
{
	return var_2;
}

void Expression::result()
{
	if(operation=='/')
		cout<<"var_1/var_2: "<<var_1/var_2<<endl;
	if(operation=='*')
		cout<<"var_1*var_2: "<<var_1*var_2<<endl;
}