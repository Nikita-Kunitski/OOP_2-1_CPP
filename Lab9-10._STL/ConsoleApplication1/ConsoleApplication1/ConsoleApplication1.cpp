// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_set>
#include <stack>
//#include <initializer_list>
using namespace std;


void output(unordered_set<int> object)
{
	for(auto i:object)
		cout<<"Element:"<<i<<endl;
	cout<<endl;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int i=0;
	unordered_set<int> object;
	object.insert(5);
	object.insert(135);
	object.insert(10);
	cout<<"\tFirst set\n";
	output(object);
	
		object.erase(5);
		object.insert(84);
		object.erase(135);
		object.insert(5);

	cout<<"\tSecond set\n";
	output(object);
		
		cout<<"\tDemonstraition reverse iterators:\n";
		cout<<"rbegin: "<<*object.rbegin()<<endl;
		//cout<<"rend: "<<*object.rend()<<endl;

		cout<<"\tDemonstration constant's iterators\n";
		unordered_set<int>::const_iterator const_iter=object.begin();
		unordered_set<int>::const_reverse_iterator iter_rev=object.rbegin();
		cout<<"Const iterator:"<<*const_iter<<endl;
		cout<<"Const reverse iterator:"<<*iter_rev<<endl;

		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////Second container//////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////

		cout<<"\nDemonstration stack\n";
	stack<int> object_stack;
	for(auto i:object)
	{
		object_stack.push(i);
		cout<<object_stack.top()<<endl;
	}
	object.clear();
	while(!object_stack.empty())
	{
		object.insert(object_stack.top());
		object_stack.pop();
	}
	cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
	output(object);
	return 0;
}

