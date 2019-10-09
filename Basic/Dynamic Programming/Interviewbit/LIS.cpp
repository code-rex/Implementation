//For maxiumn sum

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sync ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD  1000000007 
int powm(int base,int exp,int mod=MOD) {int ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}

int calc(int i,int n,vector<int>&dp,int a[])
{
	if(i>=n)
		return 0;
	if(dp[i]!=-1)
		return dp[i];
	int ans=a[i]; 	//a[i]=1 for longest incraesing subsequence 
	for(int j=i+1;j<n;j++)
	{
		if(a[j]>=a[i])
			ans=max(ans,a[i]+calc(j,n,dp,a));
	}
	return dp[i]=ans;
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
		int ans=INT_MIN;
		vector<int>dp(n,-1);
		for(int i=0;i<n;i++){
			ans=max(ans,calc(i,n,dp,a));
		}
		cout<<ans<<endl;
	}
}

//Bottom UP
int Solution::lis(const vector<int> &arr) {
    int n=arr.size();
    int lis[n];
    for(int i=0;i<n;i++)
    {
        lis[i] = 1;
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }
    return *max_element(lis,lis+n);
}
