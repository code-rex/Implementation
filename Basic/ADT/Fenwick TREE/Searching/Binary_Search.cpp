// https://codeforces.com/contest/1208/problem/D
// https://codeforces.com/blog/entry/61364

/*Solution Approach :
For every i from N to 1, let's say the value of the si is x. So it means there are k smallest unused numbers whose sum is x. 
We simply put the k+1st number in the output permutation at this i, and continue to move left. This can be implemented using BIT 
and binary lifting.
*/

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
int binary_search(int v)
{
	int l = 1, r = n;
	while(l != r)
	{
		int mid = (l+r) / 2;
		//cout<<query(mid)<<" ";
		if(query(mid) <= v) //For upper bound index of given sum <= ,for lower bound <
			l = mid+1;
		else
			r = mid;
	}
	return l;
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
		ans[i]=binary_search(a[i]);
		update(ans[i],-ans[i]); //updating to do not compute furthur
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
