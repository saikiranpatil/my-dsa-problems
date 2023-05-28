class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(sz+2, vector<int>(sz+2, 0));
        
        for(int len=2;len<=sz+1;len++){
            for(int i=0;i+len<=sz+1;i++){
                int j=i+len;
                dp[i][j] = INT_MAX;
                
                for(int k=i+1; k<j;k++){
                    int curr = dp[i][k] + dp[k][j] + cuts[j] - cuts[i];
                    dp[i][j]=min(dp[i][j], curr);
                }
                
            }
        }
        
        return dp[0][sz+1];
    }
};