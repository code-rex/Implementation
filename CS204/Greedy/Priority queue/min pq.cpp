//minimum priority queue
#include<bits/stdc++.h>
using namespace std;
class minpq
{
	int *arr,cap,size;
	public:

		minpq(int cap)
		{
			arr=new int[cap];
			cap=cap;
			size=0;
		}
		//going up from down (during insertion and decreasekey)
    //0 indexing left=2*i+1,right=2*i+2,parent=(i-1)/2 for a given index i
		void bubbleup(int i)
		{
			while(i!=0&&arr[(i-1)/2]>arr[i])
				{
					swap(arr[(i-1)/2],arr[i]);
					i=(i-1)/2;
				}
		}
		//going down form above(during deletion(last index comes at index 0) and extractmin)
		void bubbledown(int i) 
		{ 
    		int l = 2*i+1; 
    		int r = 2*i+2; 
    		int smallest = i; 
    		if (l < size && arr[l] < arr[i]) 
        	smallest = l; 
    		if (r < size && arr[r] < arr[smallest]) 
        	smallest = r; 
    		if (smallest != i) 
    		{ 
        	swap(arr[i], arr[smallest]); 
        	bubbledown(smallest); 
    		} 
		}

		//------------------4 Function ---------------------
		void insert(int key)
		{
			if(size==cap)
				cout<<"full";
			else
			{
				//inserting at end
				size++;
				int i=size-1;
				arr[i]=key;
				//maintaining the priority queue
				bubbleup(i);
			}
		}
		void decrease_key(int i,int new_key)
		{
			arr[i]=new_key;
			bubbleup(i);
		}
		int extractmin()
		{
			if(size<=0)
				cout<<"flow";
			else if(size==1)
				{size--;return arr[0];}
			int root=arr[0];
			arr[0]=arr[size-1];
			bubbledown(0);
			return root;
		}
		void deletekey(int i)
		{
			decrease_key(i,INT_MIN);
			extractmin();
		}
		void print()
		{
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
 
};
int main()
{
	int n;
	cin>>n;
	minpq pq(n);
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		pq.insert(k);
	}
	pq.print();
	return 0;
}
