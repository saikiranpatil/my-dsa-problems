class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m*n;){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                tmp.push_back(original[i++]);
            }
            ans.push_back(tmp);
        }
        
        
        return ans;
    }
};