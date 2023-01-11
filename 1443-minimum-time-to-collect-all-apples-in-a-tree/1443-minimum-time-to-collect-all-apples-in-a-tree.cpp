class Solution {
public:
    int helper(vector<vector<int>> &graph,vector<bool> &hasApple,int node,int prev) {
        int ans = 0;
        for(int currNode : graph[node]) {
            if(currNode != prev) {
                int next = helper(graph,hasApple,currNode,node);
                if(next >= 0) ans += (next+2);
            }
        }
        return ans == 0 ? hasApple[node] ? 0 : -1 : ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = helper(graph,hasApple,0,-1);
        return ans == -1 ? 0 : ans;
    }
};