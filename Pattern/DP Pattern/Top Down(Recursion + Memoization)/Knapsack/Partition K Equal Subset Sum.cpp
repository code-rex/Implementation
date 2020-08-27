class Solution {
public:
    vector<bool> visited;
    int newTarget;
    bool dfs(vector<int>&nums, int target, int k, int currentIndex){
        if(target < 0 || currentIndex == nums.size())
            return false;
        if( k == 0)
            return true;
        //Bucket found now find other buckets
        if(target == 0)
            return dfs(nums, newTarget, k-1, 0);
        for(int i = currentIndex; i < nums.size(); i++){
            if(!visited[i]){
                //Acquire Lock to not used by any other one
                visited[i] = true;
                if(dfs(nums, target - nums[i], k, i+1))
                   return true;
                /*Here we using lock to make sure not to use same element twice, as any of these branch
                result in target == 0, we then find k-1 bucket (and previous elemenets are still locked)
                */
                //Release Lock
                visited[i] = false;
            }
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0 || *max_element(nums.begin(), nums.end()) > sum/k)    
            return false;
        int target = sum/k;
        newTarget = target;
        visited.resize(nums.size());
        visited.assign(nums.size(), false);
        //Need to make K Buckets with Equal sum -> k - 1 buckets with target sum
        return dfs(nums, target, k-1, 0);
    }
};
