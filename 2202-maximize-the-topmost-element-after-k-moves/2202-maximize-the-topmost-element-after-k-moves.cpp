class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];
        
        if(k == 0) return n >= 1 ? nums[0] : -1;
        if(k == 1) return n == 1 ? -1 : nums[1];
        if(n == 1) return k%2 != 0 ? -1 : nums[0];
        
        for(int i=0;i<min(k-1, n);i++) ans = max(ans, nums[i]);
        
        return k<n ? max(ans, nums[k]) : ans;
    }
};