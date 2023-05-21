class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int, int>> d={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int m=grid.size(), n=grid[0].size(), ans=-1;
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        vector<pair<int, int>> stk;
        pair<int, int> tmp = helper(grid);
        
        stk.push_back(tmp);
        visited[tmp.first][tmp.second]=true;
        
        queue<pair<int, int>> q;
        q.push(tmp);
        
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=curr.first + d[i].first, ny=curr.second + d[i].second;
                
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]==1){
                    visited[nx][ny]=true;
                    stk.push_back({nx, ny});
                    
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i=0;i<stk.size();i++){
            q.push(stk[i]);
        }
        
        while(!q.empty()){
            int sz=q.size();
            ans++;
            
            while(sz--){
                pair<int, int> curr=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx=curr.first + d[i].first, ny=curr.second + d[i].second;

                    if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                        if(grid[nx][ny]==1) return ans;
                        
                        visited[nx][ny]=true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return stk.size();
    }
    
    pair<int, int> helper(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return {i, j};
            }
        }
        
        return {-1,-1};
    }
};