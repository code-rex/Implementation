/*
Range given : 1 - n
Order of element is Not Maintained
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
            nums[i] = nums[i]-1;    
        for(int i=0;i<n;i++)
            nums[nums[i]%n] = nums[nums[i]%n]+n;
        for(int i=0;i<n;i++)
            if(nums[i]/n > 1) //Replace 1 with K to find K repeating numbers 
                ans.push_back(i+1);
        return ans;
    }
};
