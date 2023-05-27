class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1, INT_MIN);
        
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            int curr=0;
            
            for(int j=i;(j<i+3 && j<n); j++){
                curr+=stoneValue[j];
                dp[i]=max(dp[i], curr - dp[j+1]);
            }
        }
        
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        return "Tie";
    }
};