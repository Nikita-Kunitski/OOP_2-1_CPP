// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "set.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int *arr, size;
	cout<<"Enter size:";
	cin>>size;
	arr=new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i]=rand()%100;
		cout<<"arr:"<<arr[i]<<endl;
	}
	Set list_1(4);
	list_1+5;
	list_1+65;
	list_1+2;

	list_1.to_console();
	return 0;
}

