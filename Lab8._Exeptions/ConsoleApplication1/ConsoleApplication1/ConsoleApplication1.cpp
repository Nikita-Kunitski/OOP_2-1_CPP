// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include <cmath>
#include "List_cpp.h"
#include <iostream>
#define NDEBUG
#include <cassert>



 template <class type>
void return_value(type value, List<type> *list)
 {
	 double *arr=new double[list->getElement()];
	 type result;
	 int index=0;
	 auto min_difference=0;
	 List<type> *p=new List<type>;
	 p=list->getHead();
	 result=p->getKey();
	 min_difference=abs(value-p->getKey());
	 for(int i=0;i<list->getElement();i++)
	 {
		 arr[i]=abs(value-p->getKey());
		 if(min_difference>arr[i])
		 {
			 min_difference=arr[i];
			 result=p->getKey();
			 index=i;
		 }
		 p=p->getNext();
	 }
	 cout<<result;
 }

const int size_arr=3;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	BoolVector *vect_template=new BoolVector;
	List<BoolVector> *list_3=new List<BoolVector>;
	List<int> *list_1=new List<int>;
	List<double> *list_2=new List<double>;
	List<int> *result=new List<int>;
		List<int> *list_1_2=new List<int>;
						(*list_1_2)+65;
						(*list_1_2)+955;
						(*list_1_2)+7565;
		int index;
		do
		{
			cout<<"\n\tMenu:\n";
			cout<<"1-Add to List_1;"<<endl;
			cout<<"2-Add to List_2;"<<endl;
			cout<<"3-Add to list_3(users typedate);"<<endl;
			cout<<"4-Delete first element from List_1;"<<endl;
			cout<<"5-Get element by id (List_1)(exeption);"<<endl;
			cout<<"6-Delete first element from List_3;"<<endl;
			cout<<"7-Show List_1;"<<endl;
			cout<<"8-Enter vector;"<<endl;
			cout<<"9-Inspection on equality;"<<endl;
			cout<<"10-Lists merger;"<<endl;
			cout<<"11-Clear console;"<<endl;
			cout<<"12-Show List_3"<<endl;
			cout<<"13-Call template-function;"<<endl;
			cout<<"0-Exit;"<<endl;
			cin>>index;
			try{
				switch(index)
				{

				case 1:
					{
					(*list_1)+2; 
					(*list_1)+3;
					(*list_1)+4;
					}break;

						case 2:
							{
								(*list_2)+279.54;
								(*list_2)+18.231;
								(*list_2)+754.784;					
							}break;

						case 3:{
								BoolVector vector[size_arr]={BoolVector("100101"),BoolVector("111101"),BoolVector("100001")};
							   for (int i(0);i<size_arr;i++)
								(*list_3)+vector[i];
							   }break;

				case 4:
					{
						--(*list_1);
					}break;

						case 5:
							{
								int index;
								cout<<"Enter index:";
								cin>>index;
								list_1->getElement_by_id(index);
							}break;

						case 6:
							{
								--(*list_3);
							}break;

				case 7:
					{
						list_1->to_console();
						
					}break;

					case 8:
					{
						cout<<"\nEnter BoolVector:";
						string str;
						cin>>str;
						vect_template->setVector(str);
					}break;

				case 9:
					{
						
						cout<<"List_1:\n";
						list_1->to_console();
						cout<<"\nList_1_2:\n";
						list_1_2->to_console();
						cout<<"\n";
						list_1!=list_1_2;
					}break;
				case 10:{
					    result=(*list_1)*(*list_1_2);						
					   }break;

				case 11:
					{
					system("cls");
					}break;

					case 12:
					{
						list_3->to_console();	
					}break;
					case 13:{
						BoolVector object("111100");
						return_value(1,list_1);
							}break;
					
				}
			}
			catch(Exeption *exp)
			{
				cout<<"bla-bla";
			}


					catch(ExeptionIndex exp)		
						{
							exp.to_console();
							cout<<"\nEnter new index:";
							cin>>index;
							list_1->getElement_by_id(index);
						}
					catch (ExeptionExistence exp)
					{
						exp.to_console();
					}
					catch (ExeptionEmpty exp)
							{
								exp.to_console();
							}
					catch (ExeptoionCorrect exp)
					{
						exp.to_console();
						string str;
						cout<<"Enter Corrected Boolvector(6 symbole)";
						cin>>str;
						vect_template->setVector(str);
					}
					catch(...)
					{
						cout<<"\nError exeption\n";
					}
		}while(index!=0);
		int *a=NULL, b=5, *pb=&b;
		assert(a==NULL);
		cout<<"Assert_1 not work\n";
		assert(pb==NULL);

	return 0;
}