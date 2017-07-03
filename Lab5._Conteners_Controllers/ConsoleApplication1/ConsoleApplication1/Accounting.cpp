#include "stdafx.h"
#include "accounting.h"
#include <iostream>

using namespace std;

int Accounting::element_counter=0;
Accounting *Accounting::head=NULL;

void Accounting::add()
{
	if (!head)
	{
		head=this;
		this->next=NULL;
		this->prev=NULL;
		element_counter++;
	}
		else
		{
			Accounting* a=head;
			if(a->next==NULL)
			{
				a->next=this;
				this->next=NULL;
				this->prev=head;
				element_counter++;
			}
			else
			{
				while (a->next!=NULL)
				{
					a=a->next;
				}
				a->next=this;
				this->next=NULL;
				this->prev=a;
				element_counter++;
			}
		}
}

Accounting* Accounting::getNext()
{
	return next;
}

Accounting* Accounting::getPrev()
{
	return prev;
}

Accounting* Accounting::getHead()
{
	return head;
}

void Accounting::show_to_console()
{
	Accounting *q=head;
	int counter=0;
	if(!head)
	{
		cout<<"Empty list!\n";
	}
	else{
		while(q)
		{
			counter++;
			cout<<"\n\nElement:"<<counter<<endl;
			q->to_Console();
			q=q->next;
		}
		cout<<"\n\nQuantity elements:"<<element_counter;
	}
}

void Accounting::Delete(string Name)
{
	Accounting *temp = head;
	Accounting *current = head;
	while (head)
	{
		if (temp->getName()==Name)
		{		
			if (temp->next==NULL && temp->prev==NULL)
			{
				head->next = NULL;
				head->prev = NULL;
				head = NULL;
				delete temp;
				element_counter--;
				break;
			}
			else if (temp->prev == NULL && temp->next != NULL)
			{
				head = temp->next;
				temp->next->prev = NULL;
				head->next = temp->next->next;
				delete temp;
				element_counter--;
				current = head;
				break;
			}
			else if (temp->next == NULL && temp->prev!=NULL)
			{
				temp->prev->next = NULL;
				delete temp;
				element_counter--;
				break;
			} 
			else if (temp->next != NULL && temp->prev != NULL)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				element_counter--;
				break;
			}
		}
		temp = temp->next;
	}
}