class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs=0,re=matrix.size()-1,cs=0,ce=matrix[0].size()-1;
        vector<int> ans;
        while(rs<=re && cs<=ce){
            for(int i=cs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
            }
            rs++;
            for(int j=rs;j<=re;j++){
                ans.push_back(matrix[j][ce]);
            }
            ce--;
            if(rs<=re){
                for(int i=ce;i>=cs;i--){
                    ans.push_back(matrix[re][i]);
                }
                re--;
            }
            if(cs<=ce){
                for(int j=re;j>=rs;j--){
                    ans.push_back(matrix[j][cs]);
                }
                cs++;
            }
        }
        return ans;
    }
};