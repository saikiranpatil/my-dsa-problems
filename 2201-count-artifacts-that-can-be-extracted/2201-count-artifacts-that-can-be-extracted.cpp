class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int ans=0;
        
        vector<vector<bool>> digged(n, vector<bool>(n, false));
        
        for(auto d:dig) digged[d[0]][d[1]]=true;
        for(auto af: artifacts) if(helper(af, digged)) ans++;
        
        return ans;
    }
    
    bool helper(vector<int>& af, vector<vector<bool>>& digged){
        for(int i=af[0];i<=af[2];i++){
            for(int j=af[1];j<=af[3];j++){
                if(!digged[i][j]) return false;
            }
        }
        
        return true;
    }
};