#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class CPoint
{
	T x;
public:
	CPoint();
	CPoint(T);
	T getX();
	void to_console();
	bool operator<(int);
	bool operator>(int);
	friend std::ostream& operator << (std::ostream& output,CPoint*object)
	{
	output<<"X: "<<object->x<<endl;
	return output;
	}
	friend std::ostream& operator<<(std::ostream& output, CPoint&object){
	output<<"X: "<<object.x<<endl;
	return output;
	}
	~CPoint();
};

class Exeption
{
protected:
	int number;
	string str;
public:
	virtual void to_console()=0;
};

class OtherExeption : public Exeption
{
public:
	OtherExeption(int number, string str)
	{
		this->number=number;
		this->str=str;
	}
};

template <class T>
CPoint<T>::CPoint()
{
	x=0;
}

template<class T>
bool CPoint<T>::operator>(int val)
{
	if(x>val)
		return true;
	else return false;
}

template <class T>
bool CPoint<T>::operator<(int val)
{
	if(x<val)
		return true;
	else return false;
}

template<class T>
CPoint<T>::CPoint(T val)
{
	x=val;
}

template<class T>
T CPoint<T>::getX()
{
return x;
}

template<class T>
void CPoint<T>::to_console()
{
	cout<<"x="<<x;
}

template <class T>
CPoint<T>::~CPoint()
{}
