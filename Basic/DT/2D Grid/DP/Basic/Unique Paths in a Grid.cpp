int solve(vector<vector<int>>&a,vector<vector<int>>&dp,int n,int m)
{
    if(n<0 || m<0)
        return 0;
    if(n==0 && m==0 && a[n][m]!=1)
        return 1;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(dp[n][m]==0){
        dp[n][m]=1+solve(a,dp,n-1,m)+solve(a,dp,n,m-1);
        return dp[n][m];
    }
    else
    {
        dp[n][m]=0;
        return dp[n][m];
    }
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    solve(A,dp,n-1,m-1);
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    return solve(A,dp,n-1,m-1);
}
