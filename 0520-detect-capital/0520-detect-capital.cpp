class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        bool allCaps = isupper(word[n-1]);
        
        if(allCaps && islower(word[0])) return false;
        
        for(int i=1;i<n;i++){
            if((allCaps && islower(word[i])) || (!allCaps && isupper(word[i]))) return false;
        }
        return true;
    }
};