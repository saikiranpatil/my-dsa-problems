class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(begin(nums), end(nums));
        for (int i = 0; i < moveFrom.size(); ++i) {
            s.erase(s.find(moveFrom[i]));
            s.insert(moveTo[i]);
        }
        return vector<int>(begin(s), end(s));
    }
};