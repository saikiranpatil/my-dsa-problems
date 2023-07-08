class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int n = moveFrom.size();
        vector<int> ans;
        map<int, long> count;
        for(auto num: nums){
            count[num]++;
        }
        
        for(int i=0;i<n;i++){
            count[moveTo[i]] += count[moveFrom[i]];
            if(moveFrom[i] != moveTo[i]) count.erase(moveFrom[i]);
        }
        
        for(auto num: count){
            ans.push_back(num.first);
        }
        
        return ans;
    }
};