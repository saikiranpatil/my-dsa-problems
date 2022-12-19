class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        
        vector<vector<int>> nums(n);
        unordered_set<int> visited;
        
        for(int i=0;i<edges.size();i++){
            nums[edges[i][0]].push_back(edges[i][1]);
            nums[edges[i][1]].push_back(edges[i][0]);
        }
        
        return helper(nums, visited, source, destination);
    }
    
    bool helper(vector<vector<int>>& nums, unordered_set<int>& visited, int idx, int destination) {
        if(visited.count(idx)) return false;
        
        visited.insert(idx);
        
        for(int i=0;i<nums[idx].size();i++){
            if(nums[idx][i]==destination) return true;
            if(!visited.count(nums[idx][i]) && helper(nums,visited,nums[idx][i],destination)) return true;
        }
        
        return false;
    }
};