#include "stdafx.h"
#include <iostream>
#include "Cpoint.h"
#include <ctime>
using namespace std;

template <class T>
void return_value(T *arr, int size, int up, int down)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]>down && arr[i]<up)
			cout<<"Element:"<<arr[i]<<endl;
	}
}

int main()
{
	const int size=3;
	CPoint<int> arr[size]={int(5),int(120),int(50)};
	double *arr_1=new double[size];
	srand(time(0));
	for(int i=0;i<size;i++)
	{
		arr_1[i]=rand()%100;
		cout<<arr_1[i]<<endl;
	}
	
	return_value(arr,size,150,10);
	return 0;
}