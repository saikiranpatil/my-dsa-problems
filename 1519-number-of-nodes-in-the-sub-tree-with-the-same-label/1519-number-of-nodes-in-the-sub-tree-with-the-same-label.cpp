class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        ans.resize(n,1);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        helper(0, -1, graph, labels);
        return ans;
    }
    
    vector<int> helper(int idx, int parent, vector<vector<int>>& graph, string& labels) {
        vector<int> count(26,0);
        
        for(auto node: graph[idx]){
            if(node == parent) continue;
            
            vector<int> tmp = helper(node, idx, graph, labels);
            for(int i=0;i<26; i++){
                count[i]+=tmp[i];
            }
        }
        
        char ch = labels[idx] - 'a';
        
        count[ch]++;
        ans[idx] = count[ch];
        
        return count;
    }
};