class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        for(int i=0, ans=INT_MAX;i<nums.size();i++){
            if(abs(ans) == abs(nums[i])){
                ans = max(ans, nums[i]);
            }else if(abs(ans) > abs(nums[i])){
                ans = nums[i];
            }
            
            if(i==nums.size()-1) return ans;
        }
        
        return 0;
    }
};