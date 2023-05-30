class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int count=0, n=nums.size();
        vector<int> ans;
        
        for(int i=-k;i<n;i++){
            if(i+k<n  && nums[i+k]==key) count++;
            if(i-k-1>=0 && nums[i-k-1]==key) count--;
            
            if(i>=0 && count>0) ans.push_back(i); 
        }
        
        return ans;
    }
};