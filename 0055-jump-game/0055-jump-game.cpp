class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        
        for(int i=0;i<n;i++){
            if(i>idx) return false;
            idx=max(idx,i+nums[i]);
            if(idx>=n-1) return true;
        }
        
        return false;
    }
};