class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 500000));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = grid[i-1][j-1];
                if(i==1 && j==1) continue;
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }        
        return dp[m][n];
    }
};