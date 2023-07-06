class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(target > sum) return 0;
        if(target == sum) return n;
        
        auto checker = [nums, n, target](int len){
            int sum = 0;
        
            for(int i=0;i<len;i++){
                sum += nums[i];
            }

            for(int i=len;i<n;i++){
                if(sum>=target){
                    return true;
                }
                sum+=nums[i];
                sum-=nums[i-len];
            }

            return sum>=target;
        };
        
        int low = 1, high = n-1, mid;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(checker(mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
};