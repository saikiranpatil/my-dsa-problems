class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0, n=mat.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || j+1+i==n) ans+=mat[i][j];
            }
        }
        
        return ans;
    }
};