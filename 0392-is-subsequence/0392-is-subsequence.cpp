class Solution {
public:
    bool isSubsequence(string s, string t) {
        return lcs(s, t, s.size(), t.size()) == s.size();
    }
    
    int lcs(string str1, string str2, int n1, int n2){
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
};