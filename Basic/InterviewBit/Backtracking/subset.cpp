/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/

void subset(vector<vector<int>>&ans,vector<int>&aux,vector<int>&a,int left)
{
    ans.push_back(aux);
    for(int i=left;i<a.size();i++)
    {
        aux.push_back(a[i]);
        subset(ans,aux,a,i+1);
        aux.pop_back();
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>>ans;
    vector<int>aux;
    sort(A.begin(),A.end());
    subset(ans,aux,A,0);
    return ans;
}
