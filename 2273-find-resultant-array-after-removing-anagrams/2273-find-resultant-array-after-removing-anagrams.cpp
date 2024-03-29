class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        int n = words.size();
        
        for (int i=0;i<n;i++){
            string temp = words[i];
            sort(temp.begin(), temp.end());
            if (temp != prev){
                ans.push_back(words[i]);
            }
            prev = temp;
        }
        
        return ans;
    }
};