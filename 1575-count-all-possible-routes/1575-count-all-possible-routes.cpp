class Solution {
public:
    int mod = 1e9+7;
    int helper(vector<vector<int>>& dp, vector<int>& locations, int idx, int finish, int fuel){
        if(fuel < 0){
            return 0;
        }
        
        if(dp[idx][fuel] != -1){
            return dp[idx][fuel];
        }
        
        int ans = idx == finish;
        for(int i=0;i<locations.size();i++){
            int diff = abs(locations[i] - locations[idx]);
            if(i!=idx && diff<=fuel){
                ans = (ans + helper(dp, locations, i, finish, fuel - diff)) % mod;
            }
        }
        return dp[idx][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(201, -1));
        return helper(dp, locations, start, finish, fuel);
    }
};