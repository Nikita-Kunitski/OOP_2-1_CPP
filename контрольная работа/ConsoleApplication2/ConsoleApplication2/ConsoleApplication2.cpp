// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;

int SIZE=3;

class Vector{
protected:
	int *key;
public:
	Vector();
	Vector(int *val);
	int getKey(int);
	void setKey(int*);
	void operator+(Vector&);
	int operator()(int);
	~Vector();
};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
Vector::Vector()
{
	key=new int[SIZE];
	for(int i(0);i<SIZE;i++)
		*(key+i)=0;
}

Vector::Vector(int* val)
{
	key=new int[SIZE];
	for(int i(0);i<SIZE;i++)
		*(key+i)=val[i];
}

int Vector::getKey(int index)
{
	return *(key+index);
}

int Vector::operator()(int index)
{
	return *(key+(index-1));
}

void Vector::setKey(int *val)
{
	for(int i(0);i<SIZE;i++)
		*(key+i)=val[i];
}

void Vector::operator+(Vector& object)
{
	for(int i(0);i<SIZE;i++)
		*(key+i)=object.getKey(i);
}

Vector::~Vector(){}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

int _tmain(int argc, _TCHAR* argv[])
{
	int *arr_1=new int[SIZE];
	int *arr_2=new int[SIZE];
	srand(time(NULL));
	for(int i(0);i<SIZE;i++)
	{
		*(arr_1+i)=rand() %20;
		*(arr_2+i)=rand() %20;
	}
	Vector object_1(arr_1),object_2(arr_2),object_3;
	object_3+object_2;
	cout<<"ARRAY\n";
	for(int i(0);i<SIZE;i++)
		cout<<object_3.getKey(i)<<endl;
	cout<<"Second element:"<<object_3(2)<<endl;
	return 0;
}

