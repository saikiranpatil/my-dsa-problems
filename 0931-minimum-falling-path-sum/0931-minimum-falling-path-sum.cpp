class Solution {
public:
    int three_min(int a, int b, int c){
        return min(a,min(b,c));
    }
    
    int helper(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp){
        int n=matrix.size();
        if(x==n-1 && y>=0 && y<n) return matrix[x][y];
        if(y>=n || y<0) return INT_MAX;
        if(dp[x][y]!=INT_MAX) return dp[x][y];
        return dp[x][y]=matrix[x][y] + three_min(helper(matrix,x+1,y,dp),helper(matrix,x+1,y-1,dp),helper(matrix,x+1,y+1,dp));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<n;i++){
            ans=min(ans,helper(matrix,0,i,dp));
        }
        return ans;
    }
};