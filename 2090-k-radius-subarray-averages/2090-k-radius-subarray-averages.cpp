class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n=nums.size(), curr=0;
        vector<int> ans(n,-1);
        
        for(int i=0;i<=2*k && i<n;i++) curr+=nums[i];
        
        for(int i=k;i<n-k;i++){
            ans[i]=curr/(2*k + 1);
            if(i>=k) curr-=nums[i-k];
            if(i+k+1<n) curr+=nums[i+k+1];
        }
        
        return ans;
    }
};