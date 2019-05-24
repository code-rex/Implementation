//Inequality important
#include<bits/stdc++.h>
#define int long long
using namespace std;
int merge(int a[],int low,int mid,int high)
{
	int inversion_count=0;
	int arr[high-low+1];
	int p=low,q=mid+1,k=0;
	while (p <= mid && q <= high) {
		if(a[p]<=a[q])
			arr[k++]=a[p++];
		else{
			arr[k++]=a[q++];
			inversion_count+=(mid-p+1);
		}
	}
		while(p <= mid)
			arr[k++]=a[p++];
		while(q <= high)
			arr[k++]=a[q++];
	for(int i=0;i<k;i++)
		a[low++]=arr[i];
	return inversion_count;
}
int mergesort(int a[],int low,int high)
{
	int inversion_count=0;
	if(low<high)
	{
		int mid=(low+high)/2;
		inversion_count+=mergesort(a,low,mid);
		inversion_count+=mergesort(a,mid+1,high);
		inversion_count+=merge(a,low,mid,high);
	}
	return inversion_count;
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<mergesort(a,0,n-1)<<endl;
	}
	return 0;
}
