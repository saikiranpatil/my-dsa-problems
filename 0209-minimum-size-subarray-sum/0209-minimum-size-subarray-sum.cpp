class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), sum=0, left = -1, ans=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[++left];
                ans=min(ans, right-left+1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};