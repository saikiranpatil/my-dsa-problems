class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {        
        for(int i = 0, ans = grid.size() * grid[0].size();i < grid.size(); i++){
            for(int j=0;j < grid[0].size(); j++){
                if(grid[i][j]<0) continue;
                ans--;
            }
            if(i == grid.size() - 1) return ans;
        }
        
        return -1;
    }
};