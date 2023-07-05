class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n=nums.size(), left=-1, ans = 0, curr=0;
        for(int right=0;right<n;right++){
            curr += nums[right];
            while(curr<right-left-1){
                curr -= nums[++left];
            }
            ans = max(ans, curr);
        }
        return ans == n ? n-1 : ans;
    }
};