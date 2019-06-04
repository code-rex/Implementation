//Analysig and opening modulus only 2 case to solve out of 4
#include<bits/stdc++.h>
using namespace std;
int main()
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
		int max1,min1,max2,min2;
		max1=INT_MIN,max2=INT_MIN,min1=INT_MAX,min2=INT_MAX;
		for(int i=0;i<n;i++)
		{
			max1=max(max1,a[i]+i);
			min1=min(min1,a[i]+i);
			max2=max(max2,a[i]-i);
			min2=min(min2,a[i]-i);
		}
		int ans=max(max1-min1,max2-min2);
		cout<<ans<<endl;
	}
	return 0;
}
