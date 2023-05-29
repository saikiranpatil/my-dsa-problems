class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = (long long)k * (k + 1) / 2;
        set<int> st(nums.begin(), nums.end());
        
        for (int num : st) if (num <= k) ans += (++k) - num;
        
        return ans;
    }
};