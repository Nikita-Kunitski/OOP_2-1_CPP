#include "stdafx.h"
#include "set.h"
#include <iostream>
using namespace std;

Set::Set(int* arr, unsigned int size)
{
	value=new int[size];
	for(int i=0;i<size;i++)
	{
		value[i]=arr[i];
	}
	element_counter=size;
}

Set::Set(unsigned int Size)
{
	size=Size;
	value=new int[size];
	element_counter=0;
}

int Set::getElement(int i)
{
	return value[i];
}

void Set::operator+(int val)
{
	if(element_counter<size)
	{
		this->value[element_counter]=val;
	element_counter++;
	}
	else{
		cout<<"Set polon\n";
	}
}

int* Set::operator+(Set* object)
{
	int size_new=this->size+object->size;
	int *new_arr=new int[size_new];
	for(int i=0,j=0;i<size_new;i++,j++)
	{
		if(i<this->size)
			new_arr[i]=this->value[i];
		else{
			new_arr[i]=object->value[j];
		}

	}
	return new_arr;
}

void Set::to_console()
{
	for(int i=0;i<element_counter;i++)
	{
		cout<<"arr["<<i+1<<"]="<<value[i]<<endl;
	}
}

Set::~Set()
{}