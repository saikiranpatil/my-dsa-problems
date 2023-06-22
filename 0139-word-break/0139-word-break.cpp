class Solution {
public:
    bool helper(vector<int>& dp, string s, unordered_set<string> words, int n, int idx){
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        for(int i=idx;i<n;i++){
            if(words.find(s.substr(idx, i-idx+1)) != words.end() && helper(dp, s, words, n, i+1)){
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, -1);
        dp[n]=1;
        return helper(dp, s, words, n, 0);
    }
};