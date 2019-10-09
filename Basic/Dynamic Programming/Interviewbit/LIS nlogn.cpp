/*
1.LIS is strictly increasing sequence.
2.For Longest decreasing sub sequence reverse the input.(strictly decreasing order)
*/
int lengthOfLIS(vector<int>& a) {
      int n=a.size();
      vector<int> d(n+1, 1000000000);
	    for (int i = 0; i < n; i++) 
		    *lower_bound(d.begin(), d.end(), a[i]) = a[i];//For increasing sequence(not strictly) change to upper bound 
	
      for (int i = 0; i <= n; i++) 
		    if (d[i] == 1000000000) 
			    return i;
       
    }
    
//Same Approach with iterator

int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp;
        for (auto i : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), i);
            if (it == dp.end()) {
                dp.push_back(i);
            } else {
                *it = i;
            }
        }
        return dp.size();
    }
