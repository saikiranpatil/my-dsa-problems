class Solution {
public:
    const int mod=1000000007;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int> dp(high+1, -1);
        
        for(int i=low;i<=high;i++){
            ans = ((ans%mod)+(helper(i, zero, one, dp) % mod))%mod;
        }
        
        return ans;
    }
    
    int helper(int i, int zero, int one, vector<int>& dp){
        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans=0;
        ans+=helper(i-zero, zero, one, dp) % mod;
        ans+=helper(i-one, zero, one, dp) % mod;
        
        return dp[i]=ans;
    }
};