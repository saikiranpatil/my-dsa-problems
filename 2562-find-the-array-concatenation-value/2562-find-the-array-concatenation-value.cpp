class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int low=0, high = n-1;
        
        while(low<=high){
            if(low==high){
                ans+=nums[low];
            }else{
                int factor = log10(nums[high]);
                ans+=nums[high] + (nums[low]*pow(10,factor+1));
            }
            low++;
            high--;
        }
        
        return ans;
    }
};