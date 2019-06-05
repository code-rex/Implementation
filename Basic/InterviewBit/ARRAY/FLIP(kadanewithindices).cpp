/*
https://www.interviewbit.com/problems/flip/
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
*/

//counting maximum subarray of 0 (making all 1 equals to -1)
vector<int> Solution::flip(string p) {
    int start=0,end=0,s=0;
        int sum=0;
        int maxsum=INT_MIN;
        vector<int>ans;
        for(int i=0;i<p.length();i++)
        {
            int c=p[i]-'0';
            int value = (c==0)?1:-1;
            
            sum+=value;
            if(sum<0)
            {
                sum=0;
                s=i+1;
            }
            else if(maxsum<sum)
            {
                maxsum=sum;
                start = s;
                end = i;
            }
        }
        if(maxsum>0)
        {
            ans.push_back(start+1);
            ans.push_back(end+1);
        }
        return ans;
}
