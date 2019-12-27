/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
*/

int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1500000); //INT_MAX will creeate problem in next commented line as INT_MAX+1 will overflow
        dp[0]=0;
        for(int i=1;i<=amount;i++)
            for(int j=0;j<coins.size();j++)
                if(coins[j]<=i)
                    dp[i] = min(dp[i],dp[i-coins[j]]+1); //+1 is for minimum ways
        
        return dp[amount]==1500000?-1:dp[amount];
    }
