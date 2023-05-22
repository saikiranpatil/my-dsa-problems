class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> count;
        vector<pair<int, int>> tmp;
        
        for(auto num: nums) count[num]++;
        for(auto it: count) tmp.push_back({it.second, it.first});
        
        sort(tmp.rbegin(), tmp.rend());
        
        for(int i=0;i<k;i++) ans.push_back(tmp[i].second);
        
        return ans;
    }
};