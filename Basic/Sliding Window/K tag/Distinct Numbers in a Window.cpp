/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].
*/

vector<int> Solution::dNums(vector<int> &A, int B) {
    
    //answer array
    vector<int> ans;
    
    //initiaize n as size of an array A
    int n = A.size(); 
    
    //initialize map to store count of different elements in A
    map<int,int> m;
    
    //traverse on first B elements in A and store it in the map 
    //0 to B-1 (0 based indexed)
    for(int i = 0; i < B; i++)
    {
        m[A[i]]++;
    }
    
    //put the count of first subarray of different elements in ans array
    ans.push_back(m.size());
    
    //traverse on rest of the array
    for(int i = B; i < n; i++)
    {
        //decrease the count of first element of previous subarray
        m[A[i-B]]--;
        
        //if count becomes 0 then remove it from the map
        if(m[A[i-B]] == 0)
            m.erase(A[i-B]);
        
        //increase the count of present element in map
        m[A[i]]++;
        
        //push the count of different element in ans array
        ans.push_back(m.size());
    }
    
    //return the answer array
    return ans;
}
