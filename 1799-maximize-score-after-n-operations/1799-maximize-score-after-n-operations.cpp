class Solution {
public:
    int dp[16][1 << 16];
    
    int help(int idx, int mask, vector<int> &nums)
    {
        if (mask == (1 << (nums.size())) - 1) return 0;
        if(dp[idx][mask] != -1) return dp[idx][mask];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (((mask >> i) & 1) == 0){
                for (int j = 0; j < nums.size(); j++){
                    if (j != i and ((mask >> j) & 1) == 0) ans = max(ans, idx * gcd(nums[i], nums[j]) + help(idx + 1, mask | (1 << i) | (1 << j), nums));
                }
            }
        }

        return dp[idx][mask] = ans;
    }
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        return help(1, 0, nums);
    }
};