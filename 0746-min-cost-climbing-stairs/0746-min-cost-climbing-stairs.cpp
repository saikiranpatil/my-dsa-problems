class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1001, -1);
        return helper(cost, dp, 0, 0);
    }
    
    int helper(vector<int>& nums, vector<int>& dp, int idx, int ans){
        if(dp[idx]!=-1) return dp[idx];
        if(idx+1>=nums.size()) return dp[idx]=ans;
        return dp[idx]=ans + min(helper(nums, dp, idx+1, nums[idx]), helper(nums, dp, idx+2, nums[idx+1]));
    }
};