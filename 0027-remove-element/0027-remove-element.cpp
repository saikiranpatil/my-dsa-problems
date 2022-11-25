class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=-1, ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[++idx],nums[i]);
                ans++;
            }
        }
        
        return ans;
    }
};