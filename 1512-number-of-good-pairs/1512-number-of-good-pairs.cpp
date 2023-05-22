class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans=0, n=nums.size();
        
        for(auto num: nums) count[num]++;
        for(auto it: count) ans+=it.second*(it.second-1)/2;
        
        return ans;
    }
};