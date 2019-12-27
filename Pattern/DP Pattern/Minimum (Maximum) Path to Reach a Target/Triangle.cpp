/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/


int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1;i<n;i++)
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] = min(j > triangle[i-1].size()-1 ? INT_MAX : triangle[i-1][j], 
                                     j-1<0 ? INT_MAX : triangle[i-1][j-1]) + triangle[i][j];
                //cout<<triangle[i][j]<<" ";
            }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
