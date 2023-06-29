class Solution {
public:
    int dp[5001][2];
    int n;
    int helper(vector<int>& prices, int idx, int isBuy){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][isBuy]!=-1){
            return dp[idx][isBuy];
        }
        if(isBuy){
            return dp[idx][isBuy] = max(helper(prices, idx+1, 0) - prices[idx], helper(prices, idx+1, 1));
        }
        return dp[idx][isBuy] = max(helper(prices, idx+2, 1) + prices[idx], helper(prices, idx+1, 0));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        n=prices.size();
        return helper(prices, 0, 1);
    }
};