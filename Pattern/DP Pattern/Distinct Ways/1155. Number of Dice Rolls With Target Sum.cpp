/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
*/

int numRollsToTarget(int d, int f, int target) {
        int mod = pow(10,9)+7;
       vector<int>ways(target+1);
       ways[0] = 1; //getting 0 from 0 dices
       //for repetition use outer extra loop
        for(int rep=1;rep<=d;rep++)
        {
            vector<int>new_ways(target+1);
            for(int i=0;i<=target;i++)
            {
                for(int face=1;face<=f;face++)
                {
                    if(i-face>=0)
                    {
                        new_ways[i]+=ways[i-face]; //ways is previous dice total ways
                        new_ways[i]%=mod;
                    }
                }
            }
            ways = new_ways;
        }
        return ways[target];
    }
