#include<bits/stdc++.h>
using namespace std;
int partition(int* a,int l,int h)
{
	int x=a[h];
	int i=l-1;
	for(int j=l;j<h;j++)
		if(a[j]<=x)
			i++,swap(a[i],a[j]);
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
