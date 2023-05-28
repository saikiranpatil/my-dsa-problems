class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int ans=0;
        int mx_count=0;
        int n=nums.size();
        unordered_map<int, int> mp;
        
        for(int i=0;i<n-1;i++) if(nums[i]==key) mp[nums[i+1]]++;
        
        for(auto it: mp){
            if(it.second>mx_count){
                mx_count=max(mx_count, it.second);
                ans=it.first;
            }
        }
        
        return ans;
    }
};