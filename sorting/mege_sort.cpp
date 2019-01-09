//merge sort using recursion
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int h)
{
     int p=l,q=m+1;
     int arr[h-l+1],k=0;
     for(int i=l;i<=h;i++)
     {
     	if(p>m)
            arr[k++]=a[q++];
     	else if(q>h)
     		arr[k++]=a[p++];
     	else if(a[p]<a[q])
     		arr[k++]=a[p++];
     	else
     		arr[k++]=a[q++];
     }
   for(int z=0;z<k;z++)
   	a[l++]=arr[z];
}
void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
	int mid=(l+h)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,h);
	merge(a,l,mid,h);
	}
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    	cout<<a[i]<<" ";
	return 0;
}
