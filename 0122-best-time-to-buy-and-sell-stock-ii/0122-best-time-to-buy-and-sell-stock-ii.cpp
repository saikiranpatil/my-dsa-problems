class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), m = prices[0];
        int ans = 0;

        for(int i=1; i<n; i++){
            if(prices[i]<=m){
                m = prices[i];
            }else{
                ans += prices[i] - m;
                m = prices[i];
            }
        }

        return ans;
    }
};