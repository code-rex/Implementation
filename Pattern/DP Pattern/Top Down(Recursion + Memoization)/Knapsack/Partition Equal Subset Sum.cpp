/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
*/

/*
Time : Bottom Up - O(target*n) - >100ms
Time : Top Down - O(2^n) - 8ms (No Sorting) (Follow this Approach)
The Overall performance of top down is good, But the worst case time complexity is huge.
Top-Down with Array (with sorting) - 4ms
Top-Down with Map (with Sorting) - 8ms
*/

class Solution {
public:
    unordered_map<int, bool> memory;
    bool dfs(vector<int>& nums, int target, int i){
        if(target == 0)
            return true;
        if(i == nums.size() || target <= 0)
            return false;
        if(memory.find(target)!=memory.end())
            return memory[target];
        return memory[target] = dfs(nums, target - nums[i], i+1) || dfs(nums, target, i+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target = sum/2;
        if(sum%2!=0)
            return false;
       return dfs(nums, target, 0);
    }
};
