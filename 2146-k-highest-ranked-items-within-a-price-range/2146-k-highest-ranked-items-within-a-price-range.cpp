class Solution {
public:
    int d[5] = {0, -1, 0, 1, 0};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<array<int, 4>> q = {{0, grid[start[0]][start[1]], start[0], start[1]}};
        grid[start[0]][start[1]] = 0;
        vector<vector<int>> ans;
        
        for(int i = 0;i < q.size();i++){
            auto [dist, price, x, y] = q[i];
            
            for(int j = 0;j < 4;j++){
                int nx = x + d[j], ny = y + d[j+1];
                
                if(min(nx, ny) >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] != 0){
                    q.push_back({dist + 1, grid[nx][ny], nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }
        
        sort(begin(q), end(q));
        
        for(auto [dist, price, x, y]: q){
            if (price >= pricing[0] && price <= pricing[1]){
                ans.push_back({x, y});
            }
            
            if(ans.size() == k){
                break;
            }
        }
        
        return ans;
    }
};