#include<bits/stdc++.h>
using namespace std;
/* This function takes last element as pivot, places 
    the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
    to left of pivot and all greater elements to right 
    of pivot */
int partition(int* a,int l,int h)
{
	int x=a[h]; // pivot 
	int i=l-1;  // Index of smaller element
	for(int j=l;j<h;j++)
		if(a[j]<=x)                 // If current element is smaller than or equal to pivot
			{
			i++;                // increment index of smaller element 
			swap(a[i],a[j]);
			}
	swap(a[i+1],a[h]);
	return i+1;
}
void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
		int pivot=partition(a,l,h);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,h);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
