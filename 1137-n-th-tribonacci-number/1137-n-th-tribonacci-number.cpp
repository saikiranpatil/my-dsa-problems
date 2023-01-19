class Solution {
public:
    vector<int> dp;
    
    void helper(){
        dp={0,1,1};
        for(int i=3;i<=37;i++){
            dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
        }
    }
    
    int tribonacci(int n) {
        helper();
        return dp[n];
    }
};