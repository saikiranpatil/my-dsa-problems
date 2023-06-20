class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0, len = 2*k + 1;
        vector<int> ans(nums.size(), -1);
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(i+1 >= len){
                if(i >= len){
                    sum -= nums[i - len];
                }
                ans[i - k] = sum / len;
            }
        }
        return ans;
    }
};