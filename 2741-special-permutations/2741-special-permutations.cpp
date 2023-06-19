int mod = 1e9+7;
int dp[14][(1 << 14)];

class Solution {
public:
    int helper(vector<int>& nums, int mask, int prev){
        if(mask == (1<<nums.size()) - 1){
            return 1;    
        }
        
        if(dp[prev][mask] != -1){
            return dp[prev][mask];
        }
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){  
            if((mask & (1<<i)) == 0 && (nums[i]%nums[prev] == 0 || nums[prev]%nums[i] == 0)){
                ans += helper(nums, mask | (1 << i), i)%mod;
                ans = ans%mod;
            }
        }
        
        return dp[prev][mask] = ans;
    }
    
    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans += helper(nums, (1 << i), i)%mod;
            ans %= mod;
        }
        return ans;
    }
};