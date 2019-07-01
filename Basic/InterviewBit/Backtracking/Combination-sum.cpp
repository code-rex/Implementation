/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]
*/


void combination(vector<vector<int>>&res,vector<int>&temp,vector<int>a,int left,int sum)
{
    int sum1=accumulate( temp.begin(),temp.end(),0 );
    if(sum==sum1 )
    {
        res.push_back(temp);
        return ;
    }
    if(sum1>sum)
        return ;
        
    for(int i=left;i<a.size();i++)
    {
        temp.push_back(a[i]);
        //if the current element does not exceed the sum recur from this element
        if(sum1+a[i]<=sum)
            combination(res,temp,a,i,sum);
        //else choose next element
        else
            combination(res,temp,a,i+1,sum);
        // remove number from list (backtracking) 
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    //sorting and removing duplicate
    sort(A.begin(),A.end());
    A.erase( unique( A.begin(), A.end() ), A.end() );
    vector<int>temp;
    vector<vector<int>>res;
    //combination
    combination(res,temp,A,0,B);
    return res;
}
