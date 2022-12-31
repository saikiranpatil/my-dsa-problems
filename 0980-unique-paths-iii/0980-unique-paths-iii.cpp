const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

class Solution {
public:
    bool valid(vector<vector<int>>& grid, int x, int y){
        int m=grid.size(), n=grid[0].size();
        return (x>=0 && x<m && y>=0 && y<n && grid[x][y]!=-1);
    }
    
    int helper(vector<vector<int>>& grid, vector<vector<bool>> visited, int x, int y, int count){
        if(grid[x][y]==2) return count==0;
        
        visited[x][y]=true;
        
        int ans=0;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(grid, nx, ny) && !visited[nx][ny]){
                ans+=helper(grid, visited, nx, ny, count - (grid[nx][ny]==0 ? 1 : 0));
            }
        }
        
        visited[x][y]=false;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int x, y, count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
                if(grid[i][j]==0) count++;
            }
        }
        
        return helper(grid, visited, x, y, count);
    }
};