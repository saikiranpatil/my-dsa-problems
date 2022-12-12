class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        vector<int> nums={1};
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]) nums[nums.size()-1]++;
            else nums.push_back(1);
        }
        
        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        
        for(int i=0;i<nums.size()-1;i++){
            ans+=min(nums[i],nums[i+1]);
        }
        
        return ans;
    }
};