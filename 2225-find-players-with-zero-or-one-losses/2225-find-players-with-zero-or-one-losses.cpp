class Solution {
public:
    int won[100001] = {0};
    int lostCount[100001] = {0};
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        
        for(auto match: matches){
            won[match[0]] = 1;
            lostCount[match[1]]++;
        }
        
        for(int i=0;i<100001;i++){
            if(won[i] == 1 && lostCount[i] == 0){
                ans[0].push_back(i);
            }else if(lostCount[i] == 1){
                ans[1].push_back(i);
            }
        }
        
        return ans;
    }
};