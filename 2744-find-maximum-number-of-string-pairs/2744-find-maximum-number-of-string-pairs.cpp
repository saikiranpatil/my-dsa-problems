class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        unordered_set<string> st;
        for(auto word: words){
            string rev = word;
            reverse(rev.begin(), rev.end());
            if(st.find(rev)!=st.end()){
                ans++;
            }
            st.insert(word);
        }
        return ans;
    }
};