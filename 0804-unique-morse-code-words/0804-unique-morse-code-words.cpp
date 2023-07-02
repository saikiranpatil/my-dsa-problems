class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mp[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(int i=0;i<words.size();i++){
            string curr = "";
            for(int j=0;j<words[i].size();j++){
                curr += mp[words[i][j] - 'a'];
            }
            st.insert(curr);
        }
        return st.size();
    }
};