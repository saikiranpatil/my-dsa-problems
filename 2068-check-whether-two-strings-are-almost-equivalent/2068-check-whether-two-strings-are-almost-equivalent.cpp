class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int count[26]={0}, n=word1.size();
        
        for(int i=0;i<n;i++){
            count[word1[i] - 'a']++;
            count[word2[i] - 'a']--;
        }
        
        for(int i=0;i<26;i++){
            if(abs(count[i]) > 3) return false;
        }
        
        return true;
    }
};