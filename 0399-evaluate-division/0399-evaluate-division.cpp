class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graphs;
        vector<double> ans;
        int n=equations.size();
        
        for(int i=0;i<n;i++){
            graphs[equations[i][0]][equations[i][1]]=values[i];
            graphs[equations[i][1]][equations[i][0]]=1.0 / values[i];
        }
        
        for(int i=0;i<queries.size();i++){
            double currAns=-1.0;
            if(graphs.find(queries[i][0])!=graphs.end() && graphs.find(queries[i][1])!=graphs.end()){
                unordered_set<string> visited;
                double currNum=1.0;
                
                helper(graphs, visited, queries[i][0], queries[i][1], currNum, currAns);
            }
            
            ans.push_back(currAns);
        }
        
        return ans;
    }
    
    void helper(unordered_map<string, unordered_map<string, double>>& graphs, unordered_set<string>& visited, string start, string end, double num, double& ans){
        visited.insert(start);
        
        if(start==end){
            ans=num;
            return;
        }
        
        for(auto newGraph: graphs[start]){
            if(visited.find(newGraph.first)==visited.end()) helper(graphs, visited, newGraph.first, end, num * newGraph.second, ans);
        }
    }
};