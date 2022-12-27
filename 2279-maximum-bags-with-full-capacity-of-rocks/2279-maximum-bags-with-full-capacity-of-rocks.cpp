class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size(),count=0,ans=0;
        vector<int> nums(n);
        
        for(int i=0;i<n;i++) nums[i]=capacity[i]-rocks[i];
        sort(nums.begin(),nums.end());
        while(ans<n && count+nums[ans]<=additionalRocks) count+=nums[ans++];
        
        return ans;
    }
};