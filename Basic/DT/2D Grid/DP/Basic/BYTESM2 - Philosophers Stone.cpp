/*
  1)He starts by choosing any tile in the first row, and collects the philosopher’s stones on that tile. Then, he moves to a tile in 
  the next row, collects the philosopher’s stones on the tile, and so on until he reaches the last row.
  2)When he moves from one tile to a tile in the next row, he can only move to the tile just below it or diagonally to the left or right.

  Given the values of h and w, and the number of philosopher’s stones on each tile, write a program to compute the maximum possible 
  number of philosopher’s stones Harry can grab in one single trip from the first row to the last row.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
int solve(vector<vector<int>>&dp,vector<vector<int>>&a,int n,int m)
{
	if(m<0 || n>=a.size() || m>=a[0].size())
		return INT_MIN;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(n==a.size()-1)
		return dp[n][m]=a[n][m];
	return dp[n][m]=a[n][m]+max(solve(dp,a,n+1,m+1),max(solve(dp,a,n+1,m),solve(dp,a,n+1,m-1)));
}
int32_t main()
{
	sync
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int>>a(n,vector<int>(m,0));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		vector<vector<int>>dp(n,vector<int>(m,-1));
		int ans=INT_MIN;
		for(int i=0;i<m;i++){
			ans=max(ans,solve(dp,a,0,i));
		}
		cout<<ans<<endl;	
	}
}
