class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        
        unordered_map<int, int> lostCount;
        unordered_set<int> won;
        
        for(auto match: matches){
            lostCount[match[1]]++;
            won.insert(match[0]);
        }
        
        for(auto match: won){
            if(lostCount[match] == 0){
                ans[0].push_back(match);
            }
        }
        
        for(auto lost: lostCount){
            if(lost.second == 1){
                ans[1].push_back(lost.first);
            }
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};