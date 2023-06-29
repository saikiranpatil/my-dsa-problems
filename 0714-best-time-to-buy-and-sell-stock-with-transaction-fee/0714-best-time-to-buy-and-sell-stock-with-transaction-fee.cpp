class Solution {
public:
    int dp[50001][2];
    int price;
    int helper(vector<int>& prices, int idx, int isBuy){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][isBuy]!=-1){
            return dp[idx][isBuy];
        }
        if(isBuy){
            return dp[idx][isBuy] = max(helper(prices, idx+1, 0) - prices[idx], helper(prices, idx+1, 1));
        }
        return dp[idx][isBuy] = max(helper(prices, idx+1, 1) + prices[idx] - price, helper(prices, idx+1, 0));
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        price=fee;
        return helper(prices, 0, 1);
    }
};