class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dx={-1,0,1,0}, dy={0,-1,0,1};
        int ans=0, m=grid.size(), n=grid[0].size();
        
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    bool flag=true;
                    queue<int> qx, qy;
                    qx.push(i);
                    qy.push(j);
                    
                    while(!qx.empty()){
                        int px=qx.front(), py=qy.front();
                        qx.pop();
                        qy.pop();
                        
                        grid[px][py]=2;
                        
                        if(px==0 || px==m-1 || py==0 || py==n-1) flag=false;
                        
                        for(int k=0;k<4;k++){
                            int nx=px+dx[k], ny=py+dy[k];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                                qx.push(nx);
                                qy.push(ny);
                            }
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        
        return ans;
    }
    
// 0 0 1 1 0 1 0 0 1 0 
// 1 1 - 1 1 0 1 1 1 0 
// 1 - 1 1 1 0 0 1 1 0 
// 0 1 1 0 0 0 0 1 0 1 
// 0 0 0 0 0 0 1 1 1 0 
// 0 1 0 1 0 1 - 1 1 1 
// 1 - 1 - 1 1 0 0 0 1 
// 1 1 1 1 1 1 0 0 0 0 
// 1 1 1 0 0 1 0 1 0 1 
// 1 1 1 0 1 1 0 1 1 0 
};