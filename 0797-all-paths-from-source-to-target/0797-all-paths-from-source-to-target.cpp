class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        helper(graph, ans, {0}, 0, graph.size());
        return ans;
    }
    
    void helper(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> tmp, int idx, int n){
        if(idx==n-1){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=0;i<graph[idx].size();i++){
            int num = graph[idx][i];
            
            tmp.push_back(num);
            helper(graph, ans, tmp, num, n);
            tmp.pop_back();
        }
    }
};