class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>& nums, vector<int>& cookies, int idx){
        if(idx<0){
            int mx = *max_element(begin(nums), end(nums));
            ans = min(ans, mx);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i] += cookies[idx];
            helper(nums, cookies, idx-1);
            nums[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> nums(k, 0);
        helper(nums, cookies, cookies.size()-1);
        return ans;
    }
};