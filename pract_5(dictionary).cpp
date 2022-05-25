#include<iostream>
using namespace  std;
struct node
{
    string key;
    string value;
    node*left;
    node*right;
};
class dic
{
    public:
    node*root=NULL;
    void create()
    {
        cout<<"Enter key: ";
        node*nn=new node;
        cin>>nn->key;
        cout<<"Enter value: ";
        cin>>nn->value;
        nn->left=NULL;
        nn->right=NULL;
        if(root==NULL)
        {
            root=nn;
        }
        else
        {
            insert(nn,root);
        }
    }
    void insert(node* m,node*root)
    {
        if(m->key > root->key)
        {
            if(root->right==NULL)
            {
                root->right=m;
            }
            else
            insert(m,root->right);
        }
        else
        {
            if(root->left==NULL)
            {
                root->left=m;
            }
            else
            insert(m,root->left);
        }
    }
    void display(node*root)
    {
    	if(root!=NULL)
    	{
		
	    display(root->left);
		cout<<root->key<<" "<<root->value<<endl;
		display(root->right);
		}
	}
	void search(node*root,string m)
	{
		int flag=0;
		if(root->key==m)
		{
			cout<<"Key found"<<endl;
			cout<<root->key<<" "<<root->value<<endl;
			flag=1;
		}
		else if(root->key < m )
		{
			search(root->right,m);
		}
		else if(root->key > m )
		{
			search(root->right,m);
		}
		else if(flag==0)
		{
			cout<<"Key not found!!"<<endl;
		}
	}
	void update(node*root, string m)
	{
		if(root->key==m)
		{
			string up;
			cout<<"Enter value to update: ";
			cin>>up;
			root->value=up;
			cout<<"Updated successfully!"<<endl;
			cout<<root->key<<" "<<root->value<<endl;
		}
		else if(root->key < m )
		{
			update(root->right,m);
		}
		else if(root->key > m )
		{
			update(root->right,m);
		}
	}
	
};
int main()
{
    dic d;
    string x;
    cout<<"----------------DICTIONAY---------------------"<<endl;
    int ch;
    cout<<"1)Insert\n2)Display\n3)Search\n4)Update\n5)Exit"<<endl;
    cout<<"----------------------------------------------"<<endl;
    do
    {
    	cout<<"Enter your choice: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			d.create();
    			break;
    		case 2:
    			d.display(d.root);
    			break;
    		case 3:
				cout<<"Enter key to search: ";
				cin>>x;
				d.search(d.root,x);
				break;
			case 4 :
				cout<<"Enter key to update it's value: ";
				cin>>x;
				d.update(d.root,x);
				break;
			case 5:
    			cout<<"Exit";
    			break;
    		default:
    			cout<<"Invalid Choice!!"<<endl;
		}
	}while(ch!=5);
	return 0;
}
