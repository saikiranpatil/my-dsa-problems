class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        int ans=0;
        
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]=-1;
        }
        
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]=1;
        }
        
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0], y=guards[i][1]; 
            
            while(x>0 && (!grid[x-1][y] || grid[x-1][y]==2)) grid[--x][y]=2;
            
            x=guards[i][0];
            while(x+1<m && (!grid[x+1][y] || grid[x+1][y]==2)) grid[++x][y]=2;
            
            x=guards[i][0];               
            while(y>0 && (!grid[x][y-1] || grid[x][y-1]==2)) grid[x][--y]=2;

            y=guards[i][1];
            while(y+1<n && (!grid[x][y+1] || grid[x][y+1]==2)) grid[x][++y]=2;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) ans++;
            }
        }
        
        return ans;
    }
    
    void printGrid(vector<vector<int>> grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
};