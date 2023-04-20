class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp={{1},{1,1}};
        
        for(int i=2;i<=rowIndex;i++){
            vector<int> curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j] = dp[i-1][j-1] + dp[i-1][j];
            }
            dp.push_back(curr);
        }
        
        return dp[rowIndex];
    }
};