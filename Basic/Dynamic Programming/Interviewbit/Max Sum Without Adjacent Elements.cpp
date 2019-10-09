/*
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.
*/

int Solution::adjacent(vector<vector<int> > &A) {
    int n=A[0].size();
    vector<int>dp(n,0);
    dp[0]=max(A[0][0],A[1][0]);
    dp[1]=max(max(A[0][0],A[1][0]),max(A[0][1],A[1][1]));
    for(int i=2;i<n;i++)
        dp[i]=max(dp[i-1],dp[i-2]+max(A[0][i],A[1][i]));
    return dp[n-1];
}
