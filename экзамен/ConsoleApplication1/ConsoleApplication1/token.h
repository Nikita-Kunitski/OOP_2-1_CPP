#pragma once
#include <iostream>
using namespace std;
class Token
{
public:
	Token(){};
	virtual void result()=0;
	~Token(){};
};

class Expression : public Token
{
protected:
	int var_1;
	int var_2;
	char operation;
public:
	Expression();
	Expression(int,int,char);
	char getOpreator();
	int getNumber_1();
	int getNumber_2();
	void result();
	~Expression(){};
};

class Exeption
{
public:
	Exeption(){};
	virtual void to_console()=0;
	~Exeption(){}
};

class Exeption_char : public Exeption
{
public:
	Exeption_char(){};
	void to_console()
	{
		cout<<"Error, false operation!"<<endl;
	}
	~Exeption_char(){};
};