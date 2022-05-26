#include<iostream>
using namespace std;
class heap
{
	public:
		void build_max_heap(int arr[],int n,int i);
		void heapify(int arr[],int n);
		void display(int arr[],int n);
};
void heap::build_max_heap(int arr[],int n,int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest=i;
	if(left < n && arr[largest] < arr[left])
	{
		largest=left;
	}
	if(right < n && arr[largest] < arr[right])
	{
		largest=right;
	}
	if(largest != i)
	{
		
		swap(arr[i], arr[largest]);
		build_max_heap(arr,n,largest);
		
	}
}
void heap::heapify(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		build_max_heap(arr,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0], arr[i]);	
		build_max_heap(arr,i,0);
	}
}
void heap::display(int arr[],int n)
{
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	{	
		cout<<arr[i]<<" ";
	}	
}
int main()
{
	heap h;
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	h.heapify(arr,n);
	h.display(arr,n);	
}
