class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1,0));
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0) dp[i][j] = i==0 ? j : i;
                else dp[i][j] = word1[i-1]==word2[j-1] ? dp[i-1][j-1] : 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        
        return dp[n1][n2];
    }
};