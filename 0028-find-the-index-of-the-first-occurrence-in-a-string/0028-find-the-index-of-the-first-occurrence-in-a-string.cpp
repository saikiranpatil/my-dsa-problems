class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(helper(haystack,needle,i) != -1) return helper(haystack,needle,i);
        }
        
        return -1;
    }
    
    int helper(string haystack, string needle,int idx) {
        for(int i=0;i<needle.size();i++){
            if(haystack[idx+i]!=needle[i]) return -1;
        }
        return idx;
    }
};