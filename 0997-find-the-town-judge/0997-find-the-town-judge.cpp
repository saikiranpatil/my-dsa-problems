class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> a(n+1), b(n+1);
        
        for(int i=0;i<trust.size();i++){
            a[trust[i][0]].push_back(trust[i][1]);
            b[trust[i][1]].push_back(trust[i][0]);
        }
        
        for(int i=1;i<=n;i++){
            if(b[i].size() == n-1 && a[i].size() == 0) return i;
        }
        
        return -1;
    }
};