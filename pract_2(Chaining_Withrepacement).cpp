/* PRACTICAL NO:-2
   COLLISION BY CHAINING WITH REPLACEMENT 
*/    
#include<iostream>
using namespace std;
struct node
{
	int key;
	string value;
	int chain;
};
class hash1
{
	public:
		node arr[10];
		hash1()
		{
			for(int i=0;i<10;i++)
			{
				arr[i].key=0;
				arr[i].value="NULL";
				arr[i].chain=-1;
			}
		}
		void insert();
		void display();
		void search();
		void del();
};
void hash1::insert()
{
	int k;
	string s;
	cout<<"Enter key:  ";
	cin>>k;
	cout<<"Enter value for "<<k<<" : ";
	cin>>s;
	int index;
	index =k % 10;
	if(arr[index].key==0)
	{
		arr[index].key=k;
		arr[index].value=s;
	}
	else
	{
		if(arr[index].key % 10==index)
		{
			for(int i=index+1;i<10;i++)
			{
				if(arr[i].key==0)
				{
					arr[i].key=k;
					arr[i].value=s;
					arr[index].chain=i;
					break;
				}
				else if(i==9)
				i=0;
		    }
		}
		else
		{
			int temp=arr[index].key;
			string temp1=arr[index].value;
			arr[index].key=k;
			arr[index].value=s;
			int ind=temp % 10;
			for(int i=index+1;i<10;i++)
			{
				if(arr[i].key==0)
				{
					arr[i].key=temp;
					arr[i].value=temp1;
					arr[ind].chain=i;
					break;
				}
				else if(i==9)
				i=0;
		    }
		}
	}
}
void hash1::display()
{

	for(int i=0;i<10;i++)
	{
		cout<<i<<"\t ";
        cout<<arr[i].key<<"\t-> "<<arr[i].value<<" \t "<<arr[i].chain<<endl;
	}
}
void hash1::search()
{
	int x;
	cout<<"Enter key to search: ";
	cin>>x;
	int index,flag =0;
	index=x % 10;
	if(arr[index].key==x)
	{
		cout<<"Key found "<<endl;
		cout<<arr[index].key<<" "<<arr[index].value<<endl;
		flag =1;
	}
	else if(arr[arr[index].chain].key==x)
	{
		cout<<"Key found "<<endl;
		cout<<arr[arr[index].chain].key<<" "<<arr[arr[index].chain].value<<endl;
		flag=1;
	}
	else if(flag==0)
	{
		cout<<"Key not found!!"<<endl;
	}
}
void hash1::del()
{
	int x;
	cout<<"Enter key to delete: ";
	cin>>x;
	int index,flag =0;
	index=x % 10;
	if(arr[index].key==x)
	{
		if(arr[index].chain==-1)
		{
			arr[index].key=0;
			arr[index].value="NULL";
			arr[index].chain=-1;
			flag =1;
		}
		else
		{
			arr[index].key=arr[arr[index].chain].key;
			arr[index].value=arr[arr[index].chain].value;
			arr[arr[index].chain].key=0;
			arr[arr[index].chain].value="NULL";
			arr[arr[index].chain].chain=-1;
			arr[index].chain=-1;
			flag =1;			
		}
	}
	else if(flag==1)
	{
		cout<<"Key not found!!"<<endl;
	}
}
int main()
{
	hash1 h;
    cout<<"\n1)Insert\n2)Display\n3)Search\n4)Delete\n5)Exit\n";
    int ch;
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
            	h.search();
            	break;
            case 4:
            	h.del();
            	break;
            case 5:
            	cout<<"Exit!";
            	break;
            default:
            	cout<<"Invalid choice!";
        }
    }while(ch!=5);
    return 0;
}
			
			
					
		
	
