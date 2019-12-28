/*
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
*/

---------------
/*
Solution Approach : Knapsack 0-1

This question eaquals to partition an array into 2 subsets whose difference is minimal
(1) S1 + S2  = S
(2) S1 - S2 = diff  

==> -> diff = S - 2 * S2  ==> minimize diff equals to  maximize S2 

Now we should find the maximum of S2 , range from 0 to S / 2, using dp can solve this
Take any example : How it is min difference of two bigger stone. a,b,c,d (a,b->b-a c,d->d-c --> d-c-(b-a) -->a+d-(b+c)

dp[x] = 1 means the sum x is possible.
things reduced to : W = sum(stones) / 2
*/

 int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum/2;
        vector<bool>dp(target,false);
        dp[0] = true; //0 sum is always possible
        for(auto stone:stones)
            for(int i=target;i>=stone;i--)
                dp[i] = dp[i] || dp[i-stone]; //current sum is possible or not
        //For equal sum partition return dp[target]
        for(int i=target;i>=0;i--)
            if(dp[i])
                return sum-2*i;
        return 0;
    }
