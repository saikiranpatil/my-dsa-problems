class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        string ans="";
        
        for(int i=0;i<n;i++){
            if(ans.size()!=0 && ((ans.back()=='A' && s[i]=='B') || (ans.back()=='C' && s[i]=='D'))) ans.pop_back();
            else ans.push_back(s[i]);
        }
        
        return ans.size();
    }
};