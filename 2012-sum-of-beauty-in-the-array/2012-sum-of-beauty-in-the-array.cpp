class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> left(n,nums[0]);
        vector<int> right(n,nums[n-1]);
        
        for(int i=1;i<n;i++){
            left[i]=max(nums[i],left[i-1]);            
        }
        
        for(int i=n-2;i>0;i--){
            right[i]=min(nums[i],right[i+1]);
        }
        
        for(int i=1;i<n-1;i++){
            if(left[i-1]< nums[i] && nums[i]< right[i+1]){
                ans+=2;
            }else if(nums[i-1]< nums[i] && nums[i]<nums[i+1]){
                ans++;
            }
        }
        
        return ans;
    }
};