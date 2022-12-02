class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN,n=nums.size();
        
        vector<int> tmp(n,nums[0]);
        for(int i=1;i<n;i++){
            tmp[i]=min(tmp[i-1],nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if(tmp[i]!=nums[i]) ans=max(ans,nums[i]-tmp[i]);
        }
        
        ans==INT_MIN ? ans=-1:ans=ans;
        
        return ans;
    }
};