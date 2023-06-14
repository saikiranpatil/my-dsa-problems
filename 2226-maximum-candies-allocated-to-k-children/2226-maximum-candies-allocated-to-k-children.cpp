class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {    
        int l = 0, r = 10000000;
        
        while(l < r) {
            long long m = (l + r + 1) / 2, cnt = 0;
            for (int i = 0; i < candies.size() && cnt < k; ++i) cnt += candies[i] / m;

            if (cnt >= k) l = m;
            else r = m - 1;
        }
        
        return l;
    }
};