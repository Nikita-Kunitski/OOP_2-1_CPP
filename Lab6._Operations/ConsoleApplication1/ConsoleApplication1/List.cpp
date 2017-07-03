#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

//int List::element_counter=0;

List::List()
{
	head=NULL;
	next=NULL;
	prev=NULL;
}

List* List::getHead()
{
	return head;
}

List* List::getNext()
{
	return next;
}

List* List::getPrev()
{
	return prev;
}

List* List::operator*(List& list)
{
	List* result=new List;
	List* first_list=new List;
	List* last_list=new List;
	last_list=list.getHead();
	this->next=last_list;
	first_list=this->getHead();
	result->head=first_list;
	result->to_console();
	return result;
}

void List::operator +(int val)
{
	if(!head)
	{
		head=this;
		this->next=NULL;
		this->prev=NULL;
		this->key=val;
		//element_counter++;
	} else if(head!=NULL)
	{
		//element_counter++;
		List *p=new List;
		p->key=val;
		p->next=head;
		head=p;
		
	}
}

void List::operator --()
{
	if(!head)
	{
		cout<<"\nEmpty List!\n";
		return;
	}
	List *p=new List;
	p=head;
	head=p->next;
	delete p;
	//element_counter--;
}

void List::to_console()
{
	List *p=this->getHead();
	if(!p)
	{
		cout<<"\nEmpty List!\n";
		return;
	}
	else{
		while(p)
		{
			cout<<"Element:"<<p->key<<endl;
			p=p->next;
		}
	}
	delete p;
}

void List::operator!=(List &list)
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

List::~List()
{}