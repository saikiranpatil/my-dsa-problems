class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size(),idx=-1;
        long long int ans=INT_MAX,l_sum=0,r_sum=0;
        
        for(int i=0;i<n;i++){
            r_sum+=nums[i];
        }
        
        for(int i=0;i<n;i++){
            l_sum+=nums[i];
            r_sum-=nums[i];
            int tmp;
            i == n-1 ? tmp=(l_sum/(i+1)) : tmp=abs((l_sum/(i+1)) - (r_sum/(n-i-1)));
            
            if(tmp<ans){
                idx=i;
                ans=tmp;
            }
        }
        
        return idx;
    }
};