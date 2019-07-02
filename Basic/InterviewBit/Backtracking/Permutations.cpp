/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
*/

void permutes(vector<vector<int>>&ans,vector<int>&a,int l,int r)
{
    if(l==r)
        ans.push_back(a);
    for(int i=l;i<=r;i++)
    {
        swap(a[l],a[i]);
        permutes(ans,a,l+1,r);
        swap(a[l],a[i]);
    }
}
vector<vector<int>> Solution::permute(vector<int> &A) {
    vector<vector<int>>ans;
    sort(A.begin(),A.end());
    int n=A.size();
    permutes(ans,A,0,n-1);
    return ans;
}
