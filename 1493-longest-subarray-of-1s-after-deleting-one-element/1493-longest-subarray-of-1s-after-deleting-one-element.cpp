class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(), left=-1, ans = 0, sum=0, curr=0;
        for(int right=0;right<n;right++){
            curr += nums[right];
            while(curr<right-left-1){
                curr -= nums[++left];
            }
            ans = max(ans, curr);
            sum+=nums[right];
        }
        return sum == n ? n-1 : ans;
    }
};