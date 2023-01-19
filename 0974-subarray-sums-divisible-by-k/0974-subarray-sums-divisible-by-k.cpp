class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> count;
        count[0]++;
        
        int ans=0, curr=0;
        for(int i=0;i<n;i++){
            curr=(curr + nums[i]%k + k) %k;
            ans+=count[curr];
            count[curr]++;
        }
        
        return ans;
    }
};