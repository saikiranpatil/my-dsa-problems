class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        for(char r=s[0];r<=s[3];r++){
            for(char c=s[1];c<=s[4];c++){                
                ans.push_back(string(1, r) + c);
            }
        }
        
        return ans;
    }
};