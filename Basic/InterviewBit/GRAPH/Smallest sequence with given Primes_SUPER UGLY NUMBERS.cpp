/*
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination 
of them as their prime factors.

Example:

Input : 
Prime numbers : [2,3,5] 
k : 5

If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be: 

Output: 
{2,3,4,5,6}

Explanation : 
4 = p1 * p1 ( 2 * 2 )
6 = p1 * p2 ( 2 * 3 )

Note: The sequence should be sorted in ascending order
*/

vector<int> Solution::solve(int A, int B, int C, int D) {
    int a[3]={A,B,C};
    vector<int>res;
    set<int>ans={A,B,C};
    
    int count=0;
    while(count<D)
    {
        auto top=ans.begin();
        res.push_back(*top);
        for(int i=0;i<3;i++)
            ans.insert((*top)*a[i]);
        ans.erase(top);
        count++;
    }
    return res;
}
