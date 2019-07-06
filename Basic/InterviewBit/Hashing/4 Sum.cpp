/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... 
Solution[i][k] < Solution[j][k])
*/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    unordered_map<int,vector<pair<int,int>>>m;
    vector<vector<int>>ans;
    int n=A.size();
    
    //Casting Problem to finding a pair given a pair
    //Traversing through each number and finding B-(A[i]+A[j])
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int rem = B-(A[i]+A[j]);
            //Founded
            if(m.find(rem) != m.end())
            {
                //can have many pair with same sum
                vector<pair<int,int>>vec = m[rem];
                for(int k=0;k<vec.size();i++)
                {
                    //pairs should not be same
                    if(i!=vec[k].first && i!=vec[k].second && j!=vec[k].second && j!=vec[k].first)
                    {
                        vector<int>aux={A[i],A[j],A[vec[k].first],A[vec[k].second]};
                        sort(aux.begin(),aux.end());
                        ans.push_back(aux);
                    }
                }
            }
            //Pushing the same along with indices
            m[A[i]+A[j]].push_back(make_pair(i,j));
        }
    }
    //Using sort+unique
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    return ans;
}
