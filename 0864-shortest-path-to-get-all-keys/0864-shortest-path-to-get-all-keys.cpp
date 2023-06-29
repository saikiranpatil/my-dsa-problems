class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int bit_start=0;
        
        unordered_map<char,int>key_bit;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(islower(grid[i][j])){
                    key_bit[grid[i][j]]=bit_start++;
                }
            }
        }

        int mask_size = (1<<bit_start);
        int mask_end = mask_size - 1;

        vector<vector<vector<bool>>>memo(m,vector<vector<bool>>(n,vector<bool>(mask_size,false)));

        vector<int>start;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    start={i,j,0} ;
                }
            }
        }

        queue<vector<int>>q;
        q.push(start);
        int step=0;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int row= q.front()[0];
                int col=q.front()[1];
                int mask=q.front()[2];
                q.pop();

                if(row<0 || row>=m || col<0 || col>=n || grid[row][col]=='#' || isupper(grid[row][col]) && (mask & (1 << key_bit[tolower(grid[row][col])]))==0) continue;

                if(islower(grid[row][col])){
                    mask |= (1<<key_bit[grid[row][col]]);
                }

                if(mask==mask_end) return step;

                if(memo[row][col][mask]) continue;

                memo[row][col][mask]=true;

                q.push({row+1,col,mask});
                q.push({row-1,col,mask});
                q.push({row,col+1,mask});
                q.push({row,col-1,mask});
            }
            step++;
        }
        return -1;
    }
};