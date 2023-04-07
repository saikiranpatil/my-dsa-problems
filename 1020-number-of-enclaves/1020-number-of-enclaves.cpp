class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0, m=grid.size(), n=grid[0].size();
        vector<int> dx={-1,0,1,0}, dy={0,-1,0,1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        
        while(!q.empty()){
            auto [px, py] = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int nx=px+dx[k], ny=py+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]==1){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    ans++;
                }
            }
        }
        
        return ans;
        
        // 0,0,0,1,1,1,0,1,1,1,1,1,0,0,0
        // 1,1,1,1,0,0,0,1,1,0,0,0,1,1,1
        // 1,1,1,0,0,1,0,1,1,1,0,0,0,1,1
        // 1,1,0,1,0,1,1,0,0,0,1,1,0,1,0
        // 1,1,1,1,0,0,0,1,1,1,0,0,0,1,1
        // 1,0,1,1,0,0,1,1,1,1,1,1,0,0,0
        // 0,1,0,0,1,1,1,1,0,0,1,1,1,0,0
        // 0,0,1,0,0,0,0,1,1,0,0,1,0,0,0
        // 1,0,1,0,0,1,0,0,0,0,0,0,1,0,1
        // 1,1,1,0,1,0,1,0,1,1,1,0,0,1,0
    }
};