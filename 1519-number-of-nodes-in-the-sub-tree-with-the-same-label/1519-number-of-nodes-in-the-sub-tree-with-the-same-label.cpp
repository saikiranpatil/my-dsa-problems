class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> count;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        ans.resize(n,1);
        count.resize(26,0);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        helper(0, -1, labels);
        return ans;
    }
    
    void helper(int idx, int parent, string& labels) {
        char chIdx = labels[idx] - 'a';
        
        int prevCount = count[chIdx];
        count[chIdx]++;
        
        for(auto node: graph[idx]){
            if(node == parent) continue;
            
            helper(node, idx, labels);
        }
        
        ans[idx] = count[chIdx] - prevCount;
    }
};