// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
const int MAX=3;

template <class Type>
class Array
{
protected:
	Type arr[MAX];
public:
	Array(Type* a)
	{
		for (int i=0;i<MAX;i++)
			arr[i]=a[i];
	}
	Type getelement(int); //по индексу
};

class myClass{
protected:
	int var1;
	float var2;
public:
	myClass() :var1(0),var2(0){};
	myClass(int v1, float v2)
	{
		var1=v1; var2=v2;
	};
	void show()
	{
		cout<<"var1="<<var1<<" var2="<<var2<<endl;
	}
};

 template <class Type>
 Type Array<Type>::getelement(int index)
 {
	return arr[index];
 }

/*template <class type, class newType>
type add(type a, type b, newType text)
{
	type sum=a+b;
	cout<<text<<endl;
return sum;
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	myClass arr[]={myClass(8,3.1),myClass(3,9.5),myClass(6,0.1)};
	int a[]={5,6,1};
	Array<myClass> mass(arr);
	mass.getelement(1).show();
	return 0;
}

