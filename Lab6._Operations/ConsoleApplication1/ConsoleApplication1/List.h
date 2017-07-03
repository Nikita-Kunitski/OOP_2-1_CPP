#pragma once

class List
{
protected:
	List* next;
	List* prev;
	int key;
	static int element_counter;
	List* head;
public:
	List();
	List* getNext();
	List* getPrev();
	List* getHead();
	void to_console();
	void operator+(int);
	void operator--();
	void operator!=(List&);
	List* operator*(List&);
	~List();
};
