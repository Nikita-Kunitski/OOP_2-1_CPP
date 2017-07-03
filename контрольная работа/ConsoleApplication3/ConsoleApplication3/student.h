#pragma once 
#include <iostream>
using namespace std;

template<class T>
class Student
{
protected:
	T name;
public:
	Student(T);
	~Student();
	T getName();
	void setName(T);
	friend std::ostream& operator <<(std::ostream& output, Student*object)
	{
	output<<object->getName();
	return output;
	};
	friend std::ostream& operator <<(std::ostream&output, Student&object)
	{
	output<<object.getName();
	return output;
	};
	bool operator ==(Student<T>&);
	T operator -(Student<T>);
};


template<class T>
T Student<T>::operator -(Student<T> object)
{
	return name-object.getName();	
}

template<class T>
Student<T>::Student(T Name)
{
	name=Name;
}

template<class T>
T Student<T>::getName()
{
return name;
}

template<class T>
void Student<T>::setName(T Name)
{
	name=Name;
}

template<class T>
Student<T>::~Student()
{}

template <class T>
bool Student<T>::operator==(Student<T> &object)
{
	if(name==object.getName())
	return true;
	else
		return false;
}
