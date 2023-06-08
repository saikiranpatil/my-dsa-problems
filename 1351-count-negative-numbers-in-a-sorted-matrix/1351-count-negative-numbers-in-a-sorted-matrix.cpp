class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = grid.size() * grid[0].size();
        
        for(int i = 0;i < grid.size(); i++){
            for(int j=0;j < grid[0].size(); j++){
                if(grid[i][j]<0) continue;
                ans--;
            }
        }
        
        return ans;
    }
};