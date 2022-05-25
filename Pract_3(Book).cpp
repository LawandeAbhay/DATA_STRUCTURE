#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	string label;
	int count;
	node*child[50];
};
class book
{
	public:
	node*root;
		void read_book();
		void display_book();
};
void book::read_book()
{
	node*nn=new node;
	root=nn;
	cout<<"Enter the name of book: ";
	cin>>root->label;
	cout<<"Enter how many chapters are there in book: ";
	cin>>root->count;
	for(int i=0;i<root->count;i++)
	{
		root->child[i]=new node;
		cout<<"Enter the name of chapter: ";
		cin>>root->child[i]->label;
		cout<<"Enter how many subsections are there in "<<root->child[i]->label<<": ";
		cin>>root->child[i]->count;
		for(int j=0;j<root->child[i]->count;j++)
		{
			root->child[i]->child[j]=new node;
			cout<<"Enter name of subsection of "<<root->child[i]->label<<": ";
			cin>>root->child[i]->child[j]->label;
			cout<<"Enter how many subsections are there in "<<root->child[i]->child[j]->label<<": ";
			cin>>root->child[i]->child[j]->count;
			for(int k=0;k<root->child[i]->child[j]->count;k++)
			{
				root->child[i]->child[j]->child[k]=new node;
				cout<<"Enter name of subsection of "<<root->child[i]->child[j]->label<<": ";
				cin>>root->child[i]->child[j]->child[k]->label;
			}
		}
	}
}
void book::display_book()
{
	cout<<"**************INDEX*************"<<endl;
	cout<<"Chapter Name- "<<root->label<<endl;
	for(int i=0;i<root->count;i++)
	{
		cout<<"chapter- "<<i+1<<" "<<root->child[i]->label<<endl;
		for(int j=0;j<root->child[i]->count;j++)
		{
			cout<<"		----"<<root->child[i]->child[j]->label<<endl;
			for(int k=0;k<root->child[i]->child[j]->count;k++)
			{
				cout<<"		--------"<<root->child[i]->child[j]->child[k]->label<<endl;
			}
		}
	}
}
int main()
{
	book b;
	b.read_book();
	b.display_book();
	return 0;
}
