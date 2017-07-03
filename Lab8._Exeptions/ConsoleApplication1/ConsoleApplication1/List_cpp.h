#pragma once

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

//int List::element_counter=0;
template <class type>
type List<type>::getKey()
{
return key;
}

template<class type>
List<type>::List()
{
	head=NULL;
	next=NULL;
	prev=NULL;
	element_counter=0;
}

template<class type>
List<type>* List<type>::getHead()
{
	return head;
}

template<class type>
List<type>* List<type>::getNext()
{
	return next;
}

template<class type>
void List<type>::getElement_by_id(int index)
{

		if(index>this->element_counter || index<0)
		{
			throw new ExeptionIndex();
		}
		else{
			List<type>*p=new List<type>;
			p=this->getHead();
			for(int i=0;i<index;i++)
			{
				p=p->getNext();
			}
			cout<<p->getKey();
		}
}

template<class type>
List<type>* List<type>::getPrev()
{
	return prev;
}

template<class type>
List<type>* List<type>::operator*(List& list)
{
	List<type> *result=new List<type>;
	List<type> *first_list=new List<type>;
	List<type> *last_list=new List<type>;
	if(!this->getHead())
	{
		throw ExeptionExistence((string)"List_1 not exist");
	}
	last_list=list.getHead();
	this->next=last_list;
	first_list=this->getHead();
	result->head=first_list;
	try{
	result->to_console();
	}
	catch (ExeptionEmpty exp)
	{
		exp.to_console();
	}
	return result;
}

template<class type>
void List<type>::operator +(type val)
{
	if(!head)
	{
		head=this;
		this->next=NULL;
		this->prev=NULL;
		this->key=val;
		this->element_counter++;
	} else if(head!=NULL)
	{
		this->element_counter++;
		List<type> *p=new List<type>;
		p->key=val;
		p->next=head;
		head=p;
		
	}
}

template<class type>
void List<type>::operator --()
{
	if(!head)
	{
		cout<<"\nEmpty List!\n";
		return;
	}
	List<type> *p=new List<type>;
	p=head;
	head=p->next;
	delete p;
	this->element_counter--;
}

template<class type>
void List<type>::to_console()
{
	List <type> *p= new List<type>;
	p=this->getHead();

		if(!p)
			{
			throw ExeptionEmpty();
			return;
			}
		else{
				while(p)
				{
					cout<<"Element:"<<p->key<<"\n";
					p=p->next;
				}
			}
	
	
	cout<<"Elements:"<<element_counter;
	delete p;
}

template<class type>
void List<type>::operator!=(List &list)
{
	bool inspection=true;
	List *p=new List;
	List *p_list=new List;
	p=this->getHead();
	p_list=list.getHead();
	while(p_list && p)
	{
		if(p->key!=p_list->key)
		{
			inspection=false;
		}
		p=p->next;
		p_list=p_list->next;
	}
	if((!p && p_list)||(p && !p_list)||(inspection==false))
	{
		cout << "\nLists are not equal!"<<endl;
		return;
	}
	else{
	cout << "\nList are equal!"<<endl;
	}
}

template<class type>
List<type>::~List()
{}

template<class type>
int List<type>::getElement()
{
	return element_counter;
}

//////////////////////////////////////////////////////////////////////////////////////////
///////////////////BOOLVECTOR/////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void BoolVector::Weigth_and_length()
{
		weigth=0;
		length=vector.size();
		for (int i=0;i<length;i++)
		{
			if(vector[i]=='1')
				weigth++;
			/*if(vector[i]!='0'&& vector[i]!='1')
				throw ExeptoionCorrect();*/
		}
}

void BoolVector::setVector(string vect)
{
	vector=vect;
	for(int i=0;i<vector.length();i++)
		if(vector[i]!='0' && vector[i]!='1')
			throw ExeptoionCorrect();
}

void BoolVector::equipollent_vectors()
{
	for(int i=0;i<arr_size;i++)
	{
		if(i==arr_size-1)
			break;
		for(int j=i+1;j<arr_size;j++)
		{
			if((this[i].length==this[j].length) && (this[i].weigth==this[j].weigth))
				cout<<"\nVectors ["<<i+1<<"]="<<this[i].vector<<" and ["<<j+1<<"]="<<this[j].vector<<" is equipollent!";
		}
		
	}
	
}

void BoolVector::getVector_of_array(int units,int zeros)
{
	int count0=0,count1=0;
		for(int i=0; i<vector.size();i++)
		{
			if(vector[i]=='0' && count0<zeros)
				count0++;
			if(vector[i]=='1' && count1<units)
				count1++;
		}
		if(count0==zeros && count1==units)
			cout<<"\nBoolean vector is true:"<<vector;
		else
			cout<<"\nFalse";
}

int BoolVector::Setlength()
{
	cout<<"Length of Boolean vector: "<<length<<endl;
	return length;
}

int BoolVector::Count_1()
{
	int count=0;
	for(int i=0; i<vector.size();i++)
	{
		if(vector[i]=='1')
			count++;
	}
	return count;
}

int BoolVector::Count_0()
{
	int count=0;
	for(int i=0; i<vector.size();i++)
	{
		if(vector[i]=='0')
			count++;
	}
	return count;
}

string BoolVector::Konunktion()// продумать к чему применить  метод
{
	string v,v_res;
	cout<<"Enter Boolean vector (Konunktion):";
	cin>>v;
		for(int i=0; i<v.size();i++)
		{
			if(v[i]=='1')
				v_res.push_back(vector[i]);
			if(v[i]=='0')
				v_res.push_back('0');
		}
	return v_res;
}

string BoolVector::Disunktion()
{
	string v, v_res;
	cout<<"Enter Boolean vector (Disunktion):";
	cin>>v;
		for(int i=0; i < v.size(); i++)
		{
			if(v[i]=='0')
				v_res.push_back(vector[i]);
			if(v[i]=='1')
				v_res.push_back('1');
		}
		return v_res;
}

void BoolVector::printvector()
{
	cout<<"element:"<<vector<<endl;
}

BoolVector BoolVector::getVector()
{return vector;}

string BoolVector::Inversion()
{
	string v_res;
	cout<<"Invertion:";
	for(int i=0;i<vector.size();i++)
	{
		if(vector[i]=='1')
			v_res.push_back('0');
		if(vector[i]=='0')
			v_res.push_back('1');
	}
	return v_res;
}

int BoolVector::getWeigth()
{
	return weigth;
}

std::ostream& operator << (std::ostream& output, BoolVector * object)
{
	output<<"Vector: "<<object->vector<<" weigth: "<<object->weigth<<" length: "<<object->length <<endl;
	return output;
}

std::ostream& operator << (std::ostream& output, BoolVector & object)
{
	output<<"Vector: "<<object.vector<<" weigth: "<<object.weigth<<" length: "<<object.length <<endl;
	return output;
}

bool BoolVector::operator>(BoolVector *object)
{
	if(this->getWeigth()>object->getWeigth())
	{
		return true;
	}else{
	return false;
	}
}

const int BoolVector::operator-(BoolVector &object)
{
	return (this->getWeigth()-object.getWeigth());
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////ЗАДАНИЕ/////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

bool operator !=(string str_1,string str_2)
{
	if(str_1==str_2)
	return false;
	else return true;
}