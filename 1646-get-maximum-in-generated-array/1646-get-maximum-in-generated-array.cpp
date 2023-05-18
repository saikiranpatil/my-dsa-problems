class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(111,-1);
        
        dp[0]=0, dp[1]=1;
        int ans=0;
        
        for(int i=1;i<=n/2;i++){
            dp[2*i] = dp[i];
            dp[2*i + 1] = dp[i] + dp[i+1];
        }
        
        for(int i=0;i<=n;i++){
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};