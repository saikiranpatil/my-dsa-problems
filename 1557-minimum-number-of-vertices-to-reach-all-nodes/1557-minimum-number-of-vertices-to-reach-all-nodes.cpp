class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> found(n);
        vector<int> ans;
        
        for(int i=0;i<edges.size();i++) found[edges[i][1]]=true;
        
        for(int i=0;i<n;i++){
            if(!found[i]) ans.push_back(i);
        }
        
        return ans;
    }
};