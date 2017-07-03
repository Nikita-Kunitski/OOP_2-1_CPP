#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
protected:
	double a;
public:
	A(double A):a(A){};
	double operator +(double b)
	{
		double c, *pc;
		c=a*b;
		return c;
	}
	~A(){};
};

int main()
{
	A object(1235.154);
	double pobj;
	pobj=object+2;
	cout<<"pobj:"<<pobj<<endl;
	return 0;
}