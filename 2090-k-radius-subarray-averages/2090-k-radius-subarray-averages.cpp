class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        long long sum = 0;
        
        for(int i=0;i<n && i<2*k + 1;i++){
            sum += nums[i];
        }
        
        for(int i=0;i<n-2*k;i++){
            ans[i + k] = sum / (2*k + 1);
            sum -= nums[i];
            if(i + 2*k + 1 < n) sum += nums[i + 2*k + 1];
        }
        
        return ans;
    }
};