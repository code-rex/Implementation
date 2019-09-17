/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all 
numbers along its path.

 Note: You can only move either down or right at any point in time. 
Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1
*/

int solve(vector<vector<int>>&dp,vector<vector<int>>&A,int n,int m)
{
    //cout<<n<<" "<<m<<endl;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(n==0 && m==0)
        return A[0][0];
    if(n==0 || m==0 )
        return INT_MAX;
    dp[n][m]=A[n-1][m-1]+min(solve(dp,A,n-1,m),solve(dp,A,n,m-1));
    return dp[n][m];
}
int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size();
    if(n==0)
        return 0;
    int m=A[0].size();
    if(m==0)
        return 0;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(dp,A,n,m);
}

