class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        for(auto ch: s) count1[ch - 'a']++;
        for(auto ch: t) count2[ch - 'a']++;
        
        for(int i=0;i<26;i++) ans+=abs(count1[i] - count2[i]);
        
        return ans;
    }
};