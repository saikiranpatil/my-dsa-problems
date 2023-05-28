class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int n=pref.size();
        
        for(auto word: words){
            int idx=0;
            while(idx<n && pref[idx]==word[idx]) idx++;
            if(idx==n) ans++;
        }
        
        return ans;
    }
};