class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        
        for(auto c:t) mp[c]++;
        for(auto c: s) mp[c]--;
        
        for(auto it: mp) if(it.second>0) return it.first;
        
        return ' ';
    }
};