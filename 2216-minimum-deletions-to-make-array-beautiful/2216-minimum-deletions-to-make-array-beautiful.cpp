class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1] && (ans + i)%2==0) ans++;
        }
        
        return (n+ans)%2 == 0 ? ans : ans+1;
    }
};