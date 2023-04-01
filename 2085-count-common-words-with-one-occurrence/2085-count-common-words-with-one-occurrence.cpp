class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1, mp2;
        int ans = 0;

        for (auto word1 : words1) {
            ++mp1[word1];
        }

        for (auto word2 : words2) {
            ++mp2[word2];
        }

        for (auto word : words1) {
            if (mp1[word] == 1 && mp2[word] == 1) {
                ++ans;
            }
        }

        return ans;
    }
};