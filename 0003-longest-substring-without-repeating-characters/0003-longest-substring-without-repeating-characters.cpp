class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = -1;
        vector<int> count(256, 0);
        for(int i=0;i<s.size();i++){
            while(count[s[i]] > 0){
                count[s[++left]]--;
            }
            ans = max(ans, i - left);
            count[s[i]]++;
        }
        return ans;
    }
};