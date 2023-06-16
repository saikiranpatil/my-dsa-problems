class Solution {
public:
    int count[1001] = {0};
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> ans;
        
        for(auto rows: nums){
            for(auto num: rows){
                count[num]++;
            }
        }
        
        for(int i=1;i<1001;i++){
            if(count[i]==nums.size()){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};