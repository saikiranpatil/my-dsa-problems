class Solution {
public:
    int memo[501][501];
    
    int helper(vector<int>& piles, int start, int end, int diff) {
        if (start > end) {
            return diff > 0;
        }
        
        if (memo[start][end] != 0) {
            return memo[start][end];
        }
        
        return memo[start][end] = max(piles[start] - helper(piles, start + 1, end, -diff + piles[start]),
                                      piles[end] - helper(piles, start, end - 1, -diff + piles[end]));
    }
    
    bool stoneGame(vector<int>& piles) {
        return helper(piles, 0, piles.size() - 1, 0) > 0;
    }
};
