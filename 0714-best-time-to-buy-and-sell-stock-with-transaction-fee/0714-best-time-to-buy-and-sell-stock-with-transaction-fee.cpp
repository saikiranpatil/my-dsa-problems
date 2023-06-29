class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int buy = INT_MIN, sell = 0;
        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }
        return sell;
    }
};