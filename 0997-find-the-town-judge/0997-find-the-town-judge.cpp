class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> trust_map;
        
        for(int i=0;i<trust.size();i++){
            trust_map[trust[i][0]]--;
            trust_map[trust[i][1]]++;
        }
        
        for(int i=n;i>0;i--){
            if(trust_map[i] == n-1) return i;
        }
        
        return -1;
    }
};
