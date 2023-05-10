class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rs=0,re=n-1,cs=0,ce=n-1, num=0;
        vector<vector<int>> ans(n, vector<int>(n,1));
        
        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce;i++){
                ans[rs][i]=++num;
            }
            rs++;
            for(int j=rs;j<=re;j++){
                ans[j][ce]=++num;
            }
            ce--;
            if(rs<=re){
                for(int i=ce;i>=cs;i--){
                    ans[re][i]=++num;
                }
                re--;
            }
            if(cs<=ce){
                for(int j=re;j>=rs;j--){
                    ans[j][cs]=++num;
                }
                cs++;
            }
        }
        
        return ans;
    }
};