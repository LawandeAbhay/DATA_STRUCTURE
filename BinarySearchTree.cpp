#include<iostream>
using namespace std;
struct node
{
	int key;
	node*left;
	node*right;
};
class bst
{
	public:
		node*root=NULL;
		void create()
	    {
	        cout<<"Enter key: ";
	        node*nn=new node;
	        cin>>nn->key;
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
				cout<<root->key<<endl;
				display(root->right);
			}
		}
		void minnode(node*root)
		{
			if(root!=NULL)
			{
				while(root->left!=NULL)
				{
					root=root->left;
				}
				cout<<"Minumum element from bst is: "<<root->key<<endl;
			}
		}
		void search(node*root,int m)
		{
			int flag=0;
			if(root->key==m)
			{
				cout<<"Key found"<<endl;
				cout<<root->key<<endl;
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
	int longest_path(node*root)
	{
		
		if(root==NULL)
		{
			return 0;	
		}
		int max_left=longest_path(root->left);
		int max_right=longest_path(root->right);
		return max(max_left,max_right)+1;
	}	
	void mirror(node*root)
	{
		
		if(root!=NULL)
		{
			node*temp=NULL;
			mirror(root->left);
			mirror(root->right);
			temp=root->left;
			root->left=root->right;
			root->right=temp;
		}
	}
};
int main()
{
	bst d;
    int x;
    cout<<"----------------BINATY SEARCH TREE---------------------"<<endl;
    int ch;
    cout<<"1)Insert\n2)Display\n3)Search\n4)Longest path length\n5)Minimum element\n6)Mirror image of tree\n7)Exit"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    do
    {
    	cout<<"\nEnter your choice: ";
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
    		case 4:
    			cout<<"\nLongest Path: ";
    			x=d.longest_path(d.root);
    			cout<<x;
    			break;
			case 5:
				d.minnode(d.root);
				break;
			case 6:
				cout<<"\nMirror image of tree: ";
				d.mirror(d.root);
				break;
			case 7:
    			cout<<"Exit";
    			break;
			default:
    			cout<<"Invalid Choice!!"<<endl;
		}
	}while(ch!=7);
	return 0;
}
