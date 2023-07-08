class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.insert(begin(special), {top + 1, bottom - 1});
        sort(begin(special), end(special));
        int ans = 0, n = special.size();
        for(int i=1;i<n;i++){
            ans = max(ans, special[i] - special[i-1] - 1);
        }
        return ans;
    }
};