class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        vector<int> count(1000001, -1);
        int ans = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(count[cards[i]] != -1){
                ans = min(ans, i - count[cards[i]] + 1);
            }
            count[cards[i]]=i;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};