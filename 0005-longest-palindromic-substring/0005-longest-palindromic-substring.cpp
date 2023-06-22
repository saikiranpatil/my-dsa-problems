class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        string ans="";
        for(int len=0;len<n;len++){
            for(int i=0,j=len;j<n;i++,j++){
                if(s[i]!=s[j]) continue;
                if(len<2){
                    dp[i][j] = len+1;
                }else if(dp[i+1][j-1]>0){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                if(dp[i][j]>ans.size()){
                    ans = s.substr(i, len+1);
                }
            }
        }
        return ans;
    }
};