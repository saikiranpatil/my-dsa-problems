class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> count(24, 0);
        for(int i=0;i<24;i++){
            for(auto num: candidates){
                count[i]+=(num>>i & 1);
            }   
        }
        return *max_element(begin(count), end(count));
    }
};