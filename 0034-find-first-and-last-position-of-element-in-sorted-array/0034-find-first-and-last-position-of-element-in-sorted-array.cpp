class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int low = 0, high = nums.size() - 1;
        
        while(low<=high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                ans[0] = low;
                ans[1] = high;
                
                if(nums[high]!=target){
                    high--;
                }else if(nums[low]!=target){
                    low++;
                }else{
                    break;
                }
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};