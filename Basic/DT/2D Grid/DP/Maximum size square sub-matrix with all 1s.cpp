int solve(vector<vector<int>> a,vector<vector<int>> &dp,int n,int m)
{
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(m==0 || n==0)
    {
        dp[n][m]=a[n][m];
        return dp[n][m];
    }
    //left ,top,top-left
    int l=solve(a,dp,n,m-1);
    int t=solve(a,dp,n-1,m);
    int tl=solve(a,dp,n-1,m-1);
    if(a[n][m]!=0){
        dp[n][m]=1+min(l,min(t,tl));
        return dp[n][m];
    }
    else
    {
        return dp[n][m]=0;
    }
}
int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    solve(A,dp,n-1,m-1);
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            ans=max(ans,dp[i][j]);
    ans=pow(ans,2);
    return ans;
}
