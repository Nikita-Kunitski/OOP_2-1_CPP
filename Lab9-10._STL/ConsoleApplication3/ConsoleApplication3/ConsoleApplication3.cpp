// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <stack>
#include <functional>
#include "Documents.h"
#include <algorithm>


struct sorting
			{
				bool operator() (Documents* object1, Documents* object2)
				{
					if(object1->getName()[0] < object2->getName()[0])
						return true;
					if(object1->getName()[0] > object2->getName()[0])
						return false;
				}
			} sort_object;

int _tmain(int argc, _TCHAR* argv[])
{
	
	cout<<"\tDemonstration 3 Project\n";
	Documents *doc_1=new Documents("Pasport");
	Documents *doc_2=new Documents("Quittance");
	Documents *doc_3=new Documents("License");
	Documents *doc_4=new Documents("Driver License");
	Documents *doc_5=new Documents("Reference");
	Documents *doc_6=new Documents("Invoice");
	std::multiset<Documents*,sorting> multi_obj;
	multi_obj.insert(doc_1);
	multi_obj.insert(doc_4);
	multi_obj.insert(doc_3);
	for(auto i=multi_obj.begin(); i!=multi_obj.end();i++)
		cout<<"\nElement:"<<*i;
	cout<<"\n\n";
	cout<<"//////////////////////////////////////////////////////////\n";
			cout<<"\tLower_Bound(doc_3())";
			multiset<Documents*>::iterator lower;
			lower=multi_obj.lower_bound(doc_3);
			multi_obj.erase(lower);

			for(auto i=multi_obj.begin(); i!=multi_obj.end();i++)
			cout<<"\nElement:"<<*i;
			multi_obj.insert(doc_3);
	cout<<"\n//////////////////////////////////////////////////////////\n";
	system("pause");
	cout<<"//////////////////////////////////////////////////////////\n";
			cout<<"\tUpper_Bound(doc_3())";
			multiset<Documents*>::iterator upper;
			upper=multi_obj.upper_bound(doc_3);
			multi_obj.erase(upper);
			multi_obj.insert(doc_1);
			for(auto i=multi_obj.begin(); i!=multi_obj.end();i++)
			cout<<"\nElement:"<<*i;
	cout<<"\n//////////////////////////////////////////////////////////\n";
	system("pause");
	stack<Documents*> mystack;

	for(auto i: multi_obj)
	{
			mystack.push(i);
	}
	cout<<"\n//////////////////////////////////////////////////////////\n";
	cout<<"\tOutput stack:";
	stack<Documents*>mystack_copy;
	while(!mystack.empty())
	{
		cout<<"\nelement:"<<mystack.top();
		mystack_copy.push(mystack.top());
		mystack.pop();
	}
	cout<<endl;
	cout<<"\n//////////////////////////////////////////////////////////\n";
	system("pause");
	cout<<"\n//////////////////////////////////////////////////////////\n";
	cout<<"\t Statistic\n";
	cout<<"Enter index (1.."<<multi_obj.size()<<"):";
	int index;
	cin>>index;
	multiset<Documents*>::iterator iter=multi_obj.begin();
	for(int i(1);i<index;i++)
	{
		iter++;
	}
	cout<<"\nStatidstics K for multi_obj: "<<*iter<<endl;
	cout<<"\n//////////////////////////////////////////////////////////\n";
	system("pause");
	cout<<"\n//////////////////////////////////////////////////////////\n";
	cout<<"\tMerging\n";
	multiset<Documents*>merg_container;
	for(auto i:multi_obj)
	{
		merg_container.insert(i);
		merg_container.insert(mystack_copy.top());
		mystack_copy.pop();
	}

	for(auto i:merg_container)
	{
		cout<<"Element:"<<i<<endl;
	}
	cout<<"\n//////////////////////////////////////////////////////////\n";
	system("pause");
	cout<<"\n//////////////////////////////////////////////////////////\n";
	cout<<"\tFind elements\n";
	string doc_name;
	cout<<"Enter name document:";
	cin>> doc_name;
	multiset<Documents*>::iterator iter_merge;
	bool merg=false;
	for(iter_merge=merg_container.begin();iter_merge!=merg_container.end();iter_merge++)
	{
		if((*iter_merge)->getName()==doc_name)
		{
			cout<<"Element:"<<*(iter_merge)<<endl;
			merg=true;
		}
	}
	if(merg==false)
		cout<<"\n\tThis docname not found!\n";
	cout<<"\n//////////////////////////////////////////////////////////\n";
		system("pause");
		cout<<"\n//////////////////////////////////////////////////////////\n";
		cout<<"\t\twork with STRING!!!!!!!!\n";
		string str_1="work with string";
		string str_2(str_1);
		cout<<"\nstr_1:"<<str_1<<endl;
		cout<<"Constructor coping str_2(str_1):"<<str_2<<endl;
		string str_3(str_1,10,3);
		cout<<"with symbole(str_3):"<<str_3<<endl;
		str_3.push_back('a');
		cout<<"with symbole(str_3):"<<str_3<<endl;		
		cout<<"\tSWAPING\n";
		cout<<"str_1 no swap:"<<str_1<<endl;
		str_1.swap(str_3);
		cout<<"Swap str_1(str_3)"<<str_1<<endl;
		
		cout<<"\n/////////////////////////////////////\n";
		cout<<"\tFunctor_1\n";
		
			class functor_1: protected multiset<int>
			{
			public:
				functor_1(multiset<int>& set_)
				{
					for(auto i:set_)
						this->insert(i);
				}
				void operator()(bool summa) //true - четных, false - нечетных
				{
					int sum = 0;
					auto i = begin();
					if (summa) i++;
					while (i!=end()) 
					{
					sum += *i++;
					if (i == end()) break;
					i++;
					}
					cout<<"\nsumma:"<<sum<<endl;
				}
			};
			multiset<int>mult_func_1;
			for(int i(0);i<11;i++)//заполнение
				mult_func_1.insert(i);
			functor_1 func_1(mult_func_1);
			auto i=bind(func_1,placeholders::_1);//	?
			i(true);
			func_1(false);
			cout<<"\n/////////////////////////////////////\n";
			cout<<"\n/////////////////////////////////////\n";
			cout<<"\tFunctor_2\n";
			class functor_2
			{
			public:
				functor_2(){};
				void operator()(int arg_1,int arg_2)
				{
					cout<<"summa:"<<arg_1+arg_2<<endl;
				}
			};
			functor_2 func_2;
			auto var=bind(func_2,placeholders::_1,5);
			var(200,50);
		return 0;
}

