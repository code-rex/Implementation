/*
You are given an array a consisting of n integers. In one move you can choose any ai and divide it by 2 rounding down 
(in other words, in one move you can set ai:=⌊ai2⌋).

You can perform such an operation any (possibly, zero) number of times with any ai.

Your task is to calculate the minimum possible number of operations required to obtain at least k equal numbers in the array.

Don't forget that it is possible to have ai=0 after some operations, thus the answer always exists.

Input
The first line of the input contains two integers n and k (1≤k≤n≤50) — the number of elements in the array and the number of 
equal numbers required.

The second line of the input contains n integers a1,a2,…,an (1≤ai≤2⋅105), where ai is the i-th element of a.

Output
Print one integer — the minimum possible number of operations required to obtain at least k equal numbers in the array.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int32_t main()
{
	sync
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int>possible;
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		while(x>0)
		{
			possible.push_back(x);
			x/=2;
		}
	}
	int ans=INT_MAX;
	for(auto i:possible)
	{
		vector<int>cur;
		for(int j=0;j<n;j++)
		{
			int x=a[j];
			int cnt=0;
			while(x>i)
			{
				x=x/2;
				cnt++;
			}
			if(x==i)
				cur.push_back(cnt);
		}
		if(cur.size()<k)
			continue;
		sort(cur.begin(),cur.end());
		ans=min(ans,accumulate(cur.begin(),cur.begin()+k,0ll));
	}
	cout<<ans<<endl;
}

//Optimized for D2
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int32_t main()
{
	sync
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//storing the freuency of each word
	vector<vector<int>>values(2e5+11);
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		int cnt=0;
		while(x > 0)
		{
			values[x].push_back(cnt);
			cnt++;
			x=x/2;
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<2e5+1;i++)
	{
		if(values[i].size()<k)
			continue;
		sort(values[i].begin(),values[i].end());
		ans=min(ans,accumulate(values[i].begin(),values[i].begin()+k,0ll));
	}
	cout<<ans<<endl;
}
