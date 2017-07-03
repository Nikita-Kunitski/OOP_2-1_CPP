#pragma once

class Set
{
protected:
	int *value;
	unsigned int size;
    int element_counter;
public:
	Set(unsigned int);
	Set(int*,unsigned int);
	void to_console();
	int getElement(int);
	int* operator+(Set*);
	void operator+(int);
	~Set();
};