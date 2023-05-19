class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size(), n2=str2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        string ans="";

        for(int i = 0; i <= n1; i++) dp[i][0] = i;
        for(int j = 0; j <= n2; j++) dp[0][j] = j;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i=n1, j=n2;

        while(i>0 || j>0){
            if(j==0){
                ans+=str1[--i];
            }else if(i==0){
                ans+=str2[--j];
            }else if(str1[i-1]==str2[j-1]){
                ans+=str1[--i];
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str2[j-1];
                j--;
            }else{
                ans+=str1[i-1];
                i--;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};