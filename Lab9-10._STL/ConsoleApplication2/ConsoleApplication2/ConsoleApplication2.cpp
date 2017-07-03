// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Documents.h"
#include <iostream>
#include <unordered_set>
#include <memory>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Documents *doc_1=new Documents("Pasport");
	Documents *doc_2=new Documents("Quittance");
	Documents *doc_3=new Documents("License");
	Documents *doc_4=new Documents("Driver License");
	Documents *doc_5=new Documents("Reference");
	Documents *doc_6=new Documents("Invoice");
	
	unique_ptr<unordered_set<Documents*>> doc_uptr(new unordered_set<Documents*>);
	
	cout<<"\tDemonstration documents:\n";
	doc_uptr->insert(doc_1);
	doc_uptr->insert(doc_2);
	doc_uptr->insert(doc_3);
	
	for(auto i:*doc_uptr)
		cout<<"\nElement:"<<*i;

	doc_uptr->erase(doc_2);
	doc_uptr->insert(doc_4);

	cout<<"\n\n";
	for(auto i:*doc_uptr)
		cout<<"\nElement:"<<*i;

cout<<"\n\tDemonstraition reverse iterators:\n";
		cout<<"rbegin: "<<*doc_uptr->rbegin()<<endl;
		//cout<<"rend: "<<*object.rend()<<endl;

		cout<<"\n\n\tDemonstration stack:\n";
		
		shared_ptr<stack<Documents*>> stack_shptr(new stack<Documents*>);
		stack_shptr->push(doc_4);
		cout<<stack_shptr->top()<<endl;
		stack_shptr->push(doc_5);
		cout<<stack_shptr->top()<<endl;
		stack_shptr->push(doc_6);
		cout<<stack_shptr->top()<<endl;

		while(!stack_shptr->empty())
	{
		doc_uptr->insert(stack_shptr->top());
		stack_shptr->pop();
	}
		cout<<"\tMerging:";
		for(auto i=doc_uptr->begin(); i!=doc_uptr->end();i++)
		cout<<"\nElement:"<<*i;
		cout<<"\n";

		weak_ptr<stack<Documents*>> wk_ptr;
		wk_ptr.lock()=stack_shptr;
	
		unordered_set<int> a;
		cout<<"\n\n\n";
		a.insert(5);
		a.insert(120);
		a.insert(0);
		sort(a.begin(),a.end());
		for(auto i: a)
			cout<<i<<" ";


	return 0;
}

