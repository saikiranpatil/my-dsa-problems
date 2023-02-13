unordered_map<char, int> mp;
    
bool cmp(string& a, string& b){
    for(int i=0;i<min(a.length(), b.length());i++){
        if(mp[a[i]] != mp[b[i]]) return mp[a[i]] < mp[b[i]];
    }
    return a.length() < b.length();
}

class Solution {
public:
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<26;i++){
            mp[order[i]] = i;
        }
        
        vector<string> tmp = words;
        sort(words.begin(), words.end(), cmp);
        
        return words == tmp;
    }
};