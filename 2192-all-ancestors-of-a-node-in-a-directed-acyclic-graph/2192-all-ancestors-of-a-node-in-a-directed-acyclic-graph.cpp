class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<vector<int>> ans(n);
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<n;i++){
            helper(graph, ans, i, i);
        }
        
        return ans;
    }
    
    void helper(vector<vector<int>>& graph, vector<vector<int>>& ans, int idx, int curr){
        for(auto ch: graph[idx]){
            if(ans[ch].size()==0 || ans[ch].back()!=curr){
                ans[ch].push_back(curr);
                helper(graph, ans, ch, curr);
            }
        }
    }
};