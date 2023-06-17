class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;
        vector<int> ans(n, 1);
        
        for(int i=0;i<nums.size();i++){
            ans[i] *= left;
            left *= nums[i];
            
            ans[n-i-1] *= right;
            right *= nums[n-i-1];
        }
        
        return ans;
    }
};