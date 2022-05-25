#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char val;
	node*left;
	node*right;
};
class stack
{
	public:
		node*arr[100]={NULL};
		int top=-1;
		bool isempty()
		{
			if(top==-1)
			return true;
			else
			return false;
		}
		bool isfull()
		{
			if(top==99)
			return true;
			else
			return false;
		}
		void push(node*m)
		{
			if(!isfull())
			{
				top++;
				arr[top]=m;
			}
		}
		node* pop()
		{
			if(!isempty())
			{
				node*temp;
				temp=arr[top];
				top--;
				return temp;
			}
		}
};
class tree
{
	public:
		node*root=NULL;
		void create_tree(char exp[]);
		void inorder(node*);
		void postorder(node*);
		
};
void tree::create_tree(char exp[])
{
	stack s;
	int n=strlen(exp);
	for(int i=n-1;i>=0;i--)
	{
		node*nn=new node;
		nn->val=exp[i];
		nn->left=NULL;
		nn->right=NULL;
		if(isalpha(exp[i]))
		{
			s.push(nn);
		}
		else
		{
			node*temp=s.pop();
			node*temp1=s.pop();
			nn->left=temp;
			nn->right=temp1;
			s.push(nn);
		}
	}
	root=s.pop();
}
void tree::inorder(node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->val;
		inorder(root->right);
	}
}
void tree::postorder(node*root)
{
	stack s1,s2;
	node*temp=root;
	s1.push(temp);
	while(!s1.isempty())
	{
		node*temp1=s1.pop();
		s2.push(temp1);
		if(temp1->left!=NULL)
		s1.push(temp1->left);
		if(temp1->right!=NULL)
		s1.push(temp1->right);
	}
	while(!s2.isempty())
	{
		node*temp=s2.pop();
		cout<<temp->val;
	}
}
int main()
{
	tree t;
	char exp[10];
	cout<<"Enter prefix expression: ";
	cin>>exp;
	t.create_tree(exp);
	cout<<"Given expression in infix format: ";
	t.inorder(t.root);
	cout<<endl;
	cout<<"Given expression in postfix format: ";
	t.postorder(t.root);
	cout<<endl;
	return 0;
}
