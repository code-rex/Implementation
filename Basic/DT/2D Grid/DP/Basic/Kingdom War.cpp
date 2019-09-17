/*
A simple observation is to notice that the strength on each row is larger or equal to the row above and the 
strength on each column is also larger or equal to the column on its left.

This means, we don’t really need to check every single sub-array.

Note: Using Kadane’s 2D Max Sub-Matrix Sum O(N^3) will lead to TLE

Note 2: Maximum answer might be negative.
Implementation : O(n^2)
*/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int maxans=INT_MIN;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            dp[i][j]=A[i][j]+(dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]);
            maxans=max(maxans,dp[i][j]);
        }
    }
    return maxans;
}
