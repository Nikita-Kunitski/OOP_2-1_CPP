// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "student.h"
using namespace std;

template<class T>
void near (Student<T>object_1,Student<T>object_2,Student<T>&object_3)
{
	if(object_3-object_1 > object_2-object_1)
		object_3.setName(object_2.getName());
	else cout<<"\nFailed!\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	Student<int> object_1(5);
	Student<int> object_2(213);
	Student<int> object_5(0);
	near(object_1,object_2,object_5);

	Student<int> object_3(5);
	Student<int> object_4(5);
	near(object_3,object_4,object_5);
	cout<<endl<<object_5;
	return 0;
}

