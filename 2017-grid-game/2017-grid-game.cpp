class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans=LLONG_MAX,topsum=0,bottomsum=0;
        
        for(int i=0;i<grid[0].size();i++){
            topsum+=grid[0][i];
        }
        
        for(int i=0;i<grid[0].size();i++){
            topsum-=grid[0][i];
            ans=min(ans,max(topsum,bottomsum));
            bottomsum+=grid[1][i];
        }
        
        return ans;
    }
};