/*PRACTICAL:-1
  LINEAR PROBING
*/

#include<iostream>
using namespace std;
class hash1
{
	public:
		long long int hash[10];
		hash1()
		{
			for(int i=0;i<10;i++)
			{
				hash[i]=0;
			}
		}
		void insert();
		void display();
		void del();
		void search();
};
void hash1::insert()
{
	long long int x;
	int index;
	cout<<"Enter mobile number to insert: ";
	cin>>x;
	index=x % 10;
	if(hash[index]==0)
	{
		hash[index]=x;
	}
	else
	{
		for(int i=index+1;i<10;i++)
		{
			if(hash[i]==0)
			{
				hash[i]=x;
				break;
			}
			else if(i==9)
			{
				i=0;
			}
			else
			i++;
		}
	}	
}
void hash1::display()
{
	cout<<"---------------HASH TABLE-------------------"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<i<<" "<<hash[i]<<endl;
	}
}
void hash1::del()
{
	long long int x;
	cout<<"Enter mobile number to delete: ";
	cin>>x;
	int flag=0;
	for(int i=0;i<10;i++)
	{
		if(hash[i]==x)
		{
			hash[i]=0;
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"Mobile number not found!";
	}
	
}
void hash1::search()
{
	long long int x;
	cout<<"Enter mobile number to search: ";
	cin>>x;
	int flag=0;
	for(int i=0;i<10;i++)
	{
		if(hash[i]==x)
		{
			cout<<"Key Found";
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"Mobile number not found!";
	}
}
int main()
{
	hash1 h;
	int ch;
	cout<<"----------------MENU-------------------"<<endl;
	cout<<"1)Insert\n2)Display\n3)Delete\n4)Search\n5)Exit"<<endl;
	cout<<"----------------------------------------"<<endl;
	do
	{
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				h.insert();
				break;
			case 2:
				h.display();
				break;
			case 3:
				h.del();
				break;
			case 4:
				h.search();
				break;
			case 5:
				cout<<"Exit";
				break;
			default:
				cout<<"Invalid choice!!"<<endl;	
		}
	}while(ch!=5);
	return 0;
}
