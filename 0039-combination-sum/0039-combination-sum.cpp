class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void helper(vector<int>& candidates, int target, int idx, vector<int> curr){
        if(target == 0) ans.push_back(curr);
        if(target<=0) return;
        
        for(int i=idx;i<candidates.size();i++){
            if(target>=candidates[i]){
                curr.push_back(candidates[i]);
                helper(candidates, target-candidates[i], i, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, target, 0, {});
        return ans;
    }
};