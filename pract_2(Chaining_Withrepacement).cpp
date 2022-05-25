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
void hash1:: insert()
{
    int a;
    string name;
    cout<<"Enter key: ";
    cin>>a;
    cout<<"Value for "<<a<<": ";
    cin>>name;
    int index=a % 10;
    if(arr[index].key==0)
    {
        arr[index].key=a;
        arr[index].value=name;
    }
    else if(arr[index].key % 10 == index)
    {
        for(int i=index+1;i<10;i++)
        {
            if(arr[i].key == 0)
            {
                arr[i].key=a;
                arr[i].value=name;
                arr[index].chain=i;
                break;
            }
            if(i==9)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
    }
    else
    {
        int temp=arr[index].key;
        string temp1=arr[index].value;
        arr[index].key=a;
        arr[index].value=name;
        for(int i=index+1;i<10;i++)
        {
            if(arr[i].key==0)
            {
                arr[i].key=temp;
                arr[i].value=temp1;
                arr[temp % 10].chain=i;
                break;
            }
            if(i==9)
            {
                i=0;
            }
            else
            {
                i++;
            }
        }
    }
}
void hash1::display()
{
    for(int i=0;i<10;i++)
    {
        cout<<i<<"\t- ";
        cout<<arr[i].key<<"\t-> "<<arr[i].value<<" \t "<<arr[i].chain<<endl;
    }
    
}
void hash1:: search()
{
   int x,flag=0;
   cout<<"Enter key to search: ";
   cin>>x;
   int index=x % 10;
   if(arr[index].key==x)
   {
       cout<<"key found"<<endl;
       cout<<arr[index].key<<"->"<<arr[index].value;
       flag=1;
   }
   else
   {
       if(arr[arr[index].chain].key==x)
       {
            cout<<"key found"<<endl;
            cout<<arr[index].key<<"->"<<arr[index].value;
            flag=1;
       }
   }
   if(flag==0)
   {
       cout<<"Element not found!";
   }
}
int main()
{
    hash1 h;
    cout<<"\n1)Insert\n2)Display\n3)Search\n4)Exit\n";
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
            cout<<"Exit!";
            break;
            default:
            cout<<"Invalid choice!";
        }
    }while(ch!=3);
    return 0;   
}