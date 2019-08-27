//https://codeforces.com/contest/1208/problem/D
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
const int N=2e5+5;
int BIT[N], a[N], n;
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
//Search for a prefix sum (something like a lower_bound and upper bound in the prefix sums array of A)  
int binary_lifting(int v)
{
	int sum = 0;
	int pos = 0;
	
	for(int i=22; i>=0; i--)//log(n) bits required instead of 22 but for safety purpose 22
	{
		if(pos + (1 << i) <= n and sum + BIT[pos + (1 << i)] <= v) //< for lower bound and <= for upper bound
		{
			sum += BIT[pos + (1 << i)];
			pos += (1 << i);
		}
	}
 
	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}
int32_t main()
{
	sync
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i,i);
	}
	int ans[n];
	for(int i=n;i>=1;i--)
	{
		ans[i]=binary_lifting(a[i]);
		update(ans[i],-ans[i]);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
