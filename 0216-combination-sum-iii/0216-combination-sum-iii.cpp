class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(k, n, ans, tmp, 1);
        return ans;
    }
    
    void helper(int k, int n, vector<vector<int>>& ans, vector<int> tmp, int idx){
        if(k==0){
            if(n==0) ans.push_back(tmp);
            return;
        }
        
        for(int i=idx;i<=9;i++){
            if(n-i>=0){
                tmp.push_back(i);
                helper(k-1, n-i, ans, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
};