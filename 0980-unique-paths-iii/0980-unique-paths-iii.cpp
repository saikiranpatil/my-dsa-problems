const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

class Solution {
public:
    bool valid(vector<vector<int>>& grid, int x, int y){
        return (x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]!=-1);
    }
    
    int helper(vector<vector<int>>& grid, int x, int y, int count){
        if(grid[x][y]==2) return count==0;
        
        grid[x][y]=-2;
        
        int ans=0;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(grid, nx, ny) && grid[nx][ny]!=-2){
                ans+=helper(grid, nx, ny, count - (grid[nx][ny]==0 ? 1 : 0));
            }
        }
        
        grid[x][y]=0;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y, count=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
                if(grid[i][j]==0) count++;
            }
        }
        
        return helper(grid, x, y, count);
    }
};