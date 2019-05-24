//for negative numbers also
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
		int maxsum=-pow(10,7);
		for(int i=0;i<n;i++){
			cin>>a[i];
			maxsum=max(maxsum,a[i]);
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum=max(a[i],sum+a[i]);
			maxsum=max(sum,maxsum);
		}
		cout<<maxsum<<endl;
	}
	return 0;
}
