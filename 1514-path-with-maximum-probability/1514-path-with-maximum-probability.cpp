class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double>dist(n,0);
        dist[start] = 1;
        for(int i = 0; i < n - 1; i++){
            bool hasUpdate = false;
            for(int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];
                if(dist[u] * prob > dist[v]){
                    dist[v] = dist[u] * prob;
                    hasUpdate = true;
                }
                if(dist[v] * prob > dist[u]){
                    dist[u] = dist[v] * prob;
                    hasUpdate = true;
                }
            }
            if(!hasUpdate){
                break;
            }
        }
        return dist[end];
    }
};