// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List *list_1=new List;
	List *list_2=new List;
	List *result=new List;
		
		int index;
		do
		{
			cout<<"\n\tMenu:\n";
			cout<<"1-Add to List_1;"<<endl;
			cout<<"2-Add to List_2;"<<endl;
			cout<<"3-Delete first element from List_1;"<<endl;
			cout<<"4-Delete first element from List_2;"<<endl;
			cout<<"5-Show List_1;"<<endl;
			cout<<"6-Show List_2;"<<endl;
			cout<<"7-Inspection on equality;"<<endl;
			cout<<"8-Lists merger;"<<endl;
			cout<<"9-Clear console;"<<endl;
			cout<<"0-Exit;"<<endl;
			cin>>index;
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
								(*list_2)+279;
								(*list_2)+18;
								(*list_2)+754;					
							}break;

				case 3:
					{
						--(*list_1);
					}break;

						case 4:
							{
								--(*list_2);
							}break;
				case 5:
					{
						list_1->to_console();
					}break;

					case 6:
					{
						list_2->to_console();
					}break;

				case 7:
					{
						(*list_1)!=(*list_2);
					}break;
				case 8:{
					   result=(*list_1)*(*list_2);
					   }break;

				case 9:
					{
					system("cls");
					}break;
				}
		}while(index!=0);
	return 0;
}