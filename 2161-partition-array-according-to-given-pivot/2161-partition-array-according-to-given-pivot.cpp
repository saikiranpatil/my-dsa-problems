class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans, less, more;
        
        for(int i=0;i<n;i++){
            if(pivot<nums[i]) more.push_back(nums[i]);
            else if(pivot>nums[i]) less.push_back(nums[i]);
        }
        
        for(auto num:less) ans.push_back(num);
        for(int i=0;i<n - more.size() - less.size();i++) ans.push_back(pivot);
        for(auto num:more) ans.push_back(num);
        
        return ans;
    }
};