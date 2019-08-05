/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

Approach : Think of making auxiliary count array of size N. then whose count is 0 is the ans but extra space is not available
            .so we need to use this array to track the elements.swapping elements to match the indexes.

int Solution::firstMissingPositive(vector<int> &A) {
            
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>A.size() || A[i]<=0)
            continue;
            
        while(A[i]!=A[A[i]-1])
        {
            swap(A[i],A[A[i]-1]);
            
            if(A[i]>A.size() || A[i]<=0)
                 break;
        }
    }
    
    for(int i=0;i<A.size();i++)
        if(A[i]!=i+1)
            return i+1;
    return A.size()+1;
    
}
