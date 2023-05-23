class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        
        for(auto c:t) sum += c - 'a';
        for(auto c: s) sum -= c - 'a';
        
        return 'a' + sum;
    }
};