class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=n-1;i>=3;i--){
            for(int j=i-1;j>=0;j--){
                for(int k=j-1;k>=0;k--){
                    for(int l=k-1;l>=0;l--){
                        if(nums[i]==nums[j]+nums[k]+nums[l]){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};