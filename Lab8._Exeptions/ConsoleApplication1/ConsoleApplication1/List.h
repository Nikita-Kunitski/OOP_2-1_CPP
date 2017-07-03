#pragma once
#pragma warning (disable:4018)
#include <string>
#include <iostream>
using namespace std;
	const int arr_size=5;

template <class type>
class List
{
protected:
	List* next;
	List* prev;
	type key;
	type difference;
	 int element_counter;
	List* head;
public:
	List();
	List(type);
	type getKey();
	List* getNext();
	List* getPrev();
	List* getHead();
	void getElement_by_id(int);
	int getElement();
	void to_console();
	void operator+(type);
	void operator--();
	void operator!=(List&);
	List* operator*(List&);
	~List();
};

class Exeption
{
public:
	virtual void to_console()=0;
	Exeption()
	{}
	~Exeption()
	{}
};

class ExeptionExistence : public Exeption
{
	string error;
public: 
	ExeptionExistence(string str){
		error=str;
	}
	void to_console()
	{cout<<error;}
	~ExeptionExistence(){
	}
};

class ExeptionIndex : public Exeption
{
	int index;
public:
	ExeptionIndex(){
	index=0;
	}
	ExeptionIndex(int ind)
	{
		index=ind;
	}
	void SetIndex(int ind)
	{
		index=ind;	
	}
	void to_console()
	{cout<<"Error! Invalid index!";}
	~ExeptionIndex()
	{}
};

class ExeptionEmpty :public Exeption
{
public:
	ExeptionEmpty()
	{}
	void to_console()
	{cout<<"List is empty!";}
	~ExeptionEmpty()
	{}
};

class ExeptoionCorrect : public Exeption
{
public:
	ExeptoionCorrect()
	{}
	void to_console()
	{
		cout<<"Invalid BoolVector!\n";
	}
	~ExeptoionCorrect()
	{}

};

class BoolVector
{
	string vector;
	unsigned int weigth;
	int length;
public:
	BoolVector()
	{
		vector="000000";
		this->Weigth_and_length();
	};
	BoolVector(string vect)
	{
		vector=vect;
		this->Weigth_and_length();
	};
	BoolVector(const BoolVector &object)
	{
		vector=object.vector;
		length=object.length;
		weigth=object.weigth;
	};
	string Konunktion();
	string Disunktion();
	string Inversion();
	void Weigth_and_length();
	int Count_1();
	int Count_0();
	int Setlength();
	void setVector(string);
	BoolVector getVector();
	void printvector();
	void getVector_of_array(int, int);
	void equipollent_vectors();
	int getWeigth();
	friend std::ostream& operator << (std::ostream&,BoolVector*);
	friend std::ostream& operator<<(std::ostream&, BoolVector&);
	bool operator>(BoolVector*);
	bool operator>(BoolVector&);
	const int operator-(BoolVector&);
	
};