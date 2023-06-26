class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i=n1-1;i>=0;i--) {
            dp[i][n2]=s1[i]+dp[i+1][n2];
        }

        for(int j=n2-1;j>=0;j--) {
            dp[n1][j]=s2[j]+dp[n1][j + 1];
        }

        for(int i =n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                if(s1[i] != s2[j]){
                    dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
                }else{
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];     
    }
};