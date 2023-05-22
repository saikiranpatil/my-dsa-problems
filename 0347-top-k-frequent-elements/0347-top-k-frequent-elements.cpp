class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> count;
        vector<pair<int, int>> tmp;
        
        for(auto num: nums) count[num]++;
        for(auto it: count) tmp.push_back({it.second, it.first});
        
        sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
        
        int idx=0;
        
        while(k--) ans.push_back(tmp[idx++].second);
        
        return ans;
    }
};