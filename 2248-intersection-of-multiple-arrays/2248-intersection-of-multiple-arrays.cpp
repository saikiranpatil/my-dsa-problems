class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans, count(1001);
        
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                count[nums[i][j]]++;
            }
        }
        
        for(int i=0; i<count.size(); i++){
            if(count[i]==nums.size()){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};