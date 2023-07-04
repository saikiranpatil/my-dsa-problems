class Solution {
public:
    int helper(vector<vector<int>>& dp, int n, int idx){
        if(dp[n][idx] != -1) return dp[n][idx];
        if(n==1) return dp[n][idx] = idx;
        int ans = 0;
        for(int i=idx;i>0;i--){
            ans += helper(dp, n-1, i);
        }
        return dp[n][idx] = ans;
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6, -1));
        return helper(dp, n, 5);
    }
};