class Solution {
public:
    int maxProfit(vector<int>& prices) {
        for(int i=1, ans=0;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                ans+=prices[i]-prices[i-1];
            }
            if(i==prices.size()-1){
                return ans;
            }
        }
        return 0;
    }
};