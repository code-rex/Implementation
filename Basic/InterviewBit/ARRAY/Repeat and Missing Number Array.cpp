/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.
*/

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
		long long sum=0,sum1=0,sums=0,sums1=0;
		sum=n*(n+1)/2;
		sums=n*(n+1)*(2*n+1)/6;
		for(int i=0;i<n;i++)
		{
			sum1+=(long long)a[i];
			sums1+=(long long)pow(a[i],2);
		}
		long long p=sum1-sum;
		long long q=(sums1-sums)/p;
		long long r=(p+q)/2;
		long long m=(q-p)/2;
		cout<<r<<" "<<m<<endl;
	}
	return 0;
}
