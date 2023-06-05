class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for(auto num: nums) count[num]++;
        for(auto it: count) if(it.second%2!=0) return false;
        
        return true;
    }
};