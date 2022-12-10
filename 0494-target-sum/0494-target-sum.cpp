class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),sum=0;
        target=abs(target);
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        
        int num = (target + sum)/2;
        if((target + sum)%2 == 1 || target>sum) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(num+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=num;j++){
                if(j>=nums[i-1]) dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][num];
    }
};