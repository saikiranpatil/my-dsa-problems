class Solution {
public:
    string reverseStr(string str) {
        int n = str.length();

        for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
        
        return str;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string rev=reverseStr(s);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rev[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][n];
    }
};