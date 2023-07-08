class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<string> ans;
        string prev = "";
        for (auto word : words)
        {
            string temp = word;
            sort(temp.begin(), temp.end());
            if (temp != prev)
            {
                ans.push_back(word);
            }
            prev = temp;
        }
        return ans;
    }
};