class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            graph[x].push_back({y,succProb[i]});
            graph[y].push_back({x,succProb[i]});
        }
        vector<double> nums(n,0.0);
        nums[start]=1.0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:graph[curr]){
                double currNode=it.first;
                double currProb=it.second;
                double newProb=nums[curr]*currProb;
                if(newProb>nums[currNode]){
                    nums[currNode]=newProb;
                    q.push(currNode);
                }
            }
        }
        return nums[end];
    }
};