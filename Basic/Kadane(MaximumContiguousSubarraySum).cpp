//for negative numbers also
//when all numbers are negative the biggest one is ans
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
		int maxsum=a[0];
		int sum=a[0]; //current sum
		for(int i=1;i<n;i++)
		{
			sum=max(a[i],sum+a[i]);
			maxsum=max(sum,maxsum);
		}
		cout<<maxsum<<endl;
	}
	return 0;
}
