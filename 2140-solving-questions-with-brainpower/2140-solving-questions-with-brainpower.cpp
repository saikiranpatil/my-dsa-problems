class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1, 0);
        
        for(int i=n-1;i>=0;i--){
            int nextIdx = i + 1 + questions[i][1];
            
            if(nextIdx >= n) dp[i] = questions[i][0];
            else dp[i] = questions[i][0] + dp[nextIdx];
            
            dp[i]=max(dp[i+1], dp[i]);
        }
        
        return dp[0];
    }
};