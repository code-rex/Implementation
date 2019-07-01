/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
*/
//Time : O(2^n)
// Think of DFS Approach and the tree structure of recursion tree

void combination(vector<int>&temp,vector<vector<int>>&res,int n,int left,int k)
{
    if(k==0)
    {
        res.push_back(temp);
        return ;
    }
    for(int i=left;i<=n;i++)
    {
        temp.push_back(i);
        //recur for next element
        combination(temp,res,n,i+1,k-1);
        //recur back if k exceeed(backtracking)
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector<int>temp;
    vector<vector<int>>res;
    if(B>A)
        return res;
        
    combination(temp,res,A,1,B);
    return res;
}
