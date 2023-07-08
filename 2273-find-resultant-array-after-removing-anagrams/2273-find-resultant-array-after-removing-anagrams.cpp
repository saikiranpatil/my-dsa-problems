class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        auto sort_str = [](string str){
            sort(begin(str), end(str));
            return str;
        };
        
        vector<string> ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            ans.push_back(words[i]);
            string curr = sort_str(words[i]);
            while(i+1<n && sort_str(words[i+1]) == curr){
                i++;
            }
        }
        return ans;
    }
};