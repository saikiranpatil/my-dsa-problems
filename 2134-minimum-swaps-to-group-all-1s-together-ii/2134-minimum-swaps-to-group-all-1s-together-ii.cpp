class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count=0, n=nums.size();
        int zero_count=0, ans=n;
        
        for(int i=0;i<n;i++) count+=nums[i];
        for(int i=0;i<count;i++) if(!nums[i]) zero_count++;
        ans=min(ans, zero_count);
        
        for(int i=1;i<n;i++){
            zero_count += nums[i - 1] - nums[(i + count - 1) % n];
            ans=min(ans, zero_count);
        }
        
        return ans;
    }
};