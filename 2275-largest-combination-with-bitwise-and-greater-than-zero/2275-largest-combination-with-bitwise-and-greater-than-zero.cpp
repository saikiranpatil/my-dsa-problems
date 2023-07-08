class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(24, 0);
        int n = candidates.size();
        for(int i=0;i<24;i++){
            for(int j=0;j<n;j++){
                count[i]+=(candidates[j]>>i & 1);
            }   
        }
        return *max_element(begin(count), end(count));
    }
};