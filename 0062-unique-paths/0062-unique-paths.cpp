class Solution {
public:
    int helper(vector<vector<int>>& dp, int m, int n){
        if(dp[m][n] != -1) return dp[m][n];
        if (m == 1 || n == 1) return dp[m][n] = 1;
        return dp[m][n] = helper(dp, m-1, n) + helper(dp, m, n-1);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(dp, m, n);
    }
};
