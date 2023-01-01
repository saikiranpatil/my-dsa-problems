class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size(), idx=0;
        string str="";
        vector<string> strs(n);
        
        for(int i=0;i<s.size();i++){
            if(idx==n) return false;
            
            if(s[i]==' '){
                strs[idx++]=str;
                str="";
            }else if(i==s.size()-1){
                str+=s[i];
                strs[idx++]=str;
            }else{
                str+=s[i];
            }
        }
        
        if(idx!=n) return false;
        
        unordered_map<string,char> mp;
        unordered_map<char,string> mp2;
        
        for(int i=0;i<n;i++){
            if(mp.find(strs[i])==mp.end()) mp[strs[i]]=pattern[i];
            else if(mp[strs[i]]!=pattern[i]) return false;
            
            if(mp2.find(pattern[i])==mp2.end()) mp2[pattern[i]]=strs[i];
            else if(mp2[pattern[i]]!=strs[i]) return false;
        }
        
        return true;
    }
};