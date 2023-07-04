class Solution {
public:
    int helper(vector<int>& dp, int n){
        if(dp[n]!=-1) return dp[n];
        if(n<2) return dp[n] = 1;
        int ans = n;
        for(int i=1;i<=n;i++){
            ans = max(ans, i*helper(dp, n-i));
        }
        return dp[n] = ans;
    }
    int integerBreak(int n){
        if(n<4) return n-1;
        
        vector<int> dp(n+1, -1);
        return helper(dp, n);
    }
};