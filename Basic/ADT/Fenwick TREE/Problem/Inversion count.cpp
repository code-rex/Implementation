https://www.spoj.com/problems/INVCNT/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}

const int maxn=pow(10,7);
int BIT[maxn],n;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
int32_t main()
{
	int t;
	cin>>t;
	sync
	while(t--)
	{
		cin>>n;
		int a[n],b[n];
		memset(BIT,0,sizeof(BIT));
		for(int i=0;i<n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b,b+n);
		/*
		Compressing to avoid 
		1. Negative number (as BIT cant be calculated) 
		2.Range is too low or high
		3. can be also done by making pair(index,a[i]) then sorting by second value .
		*/
		for(int i=0;i<n;i++)
			a[i]=lower_bound(b,b+n,a[i])-b+1;//Now it contains ranking
		int invcount=0;
		/*
		Approach(j>i && A[i]>A[j]) 
		1.Iterating from back satisifes 1st condition of j>i
		2.query(just sum of range) gives you cumulative sum from 1-this index (if some no. whose index(here value of array) 
		is bigger has already processed(means updated its value to 1))
		3.in the query that will not add to inv count because index is greater(and we are querying for less than our index).
		 hence only those indexes(a[i]) will matter which is less than this and already processed.
		*/
		for(int i=n-1;i>=0;i--)
		{
			invcount+=query(a[i]-1);
			update(a[i],1);
		}
		cout<<invcount<<endl;
		
	}
}
