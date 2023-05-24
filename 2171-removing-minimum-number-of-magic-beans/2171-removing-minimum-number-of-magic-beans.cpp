class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        vector<int> nums(beans.begin(), beans.end());
        sort(nums.begin(), nums.end());
        
        long long n=nums.size(), sum=0, ans=0;
        
        for(auto num: beans) sum+=num;
        for(int i=0;i<n;i++) ans=max(ans, nums[i] * (n-i));
        
        return sum - ans;
    }
};