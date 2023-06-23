class Solution {
public:
    void solve(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &ans, int idx, int n){
        if(target == 0){
            result.push_back(ans);
            return;
        }
        for(int i=idx;i<n;i++){
            if(candidates[i] > target){
                break;
            }
            ans.push_back(candidates[i]);
            solve(candidates, target - candidates[i], result, ans, i, n);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, result, ans, 0, n);
        return result;
    }
};