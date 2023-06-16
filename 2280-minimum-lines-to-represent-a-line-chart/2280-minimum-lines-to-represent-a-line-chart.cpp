class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int dx = INT_MIN;
        int dy = INT_MIN;
        int ans = 0;
        
        sort(begin(stockPrices), end(stockPrices));
        
        for(int i=1;i<stockPrices.size();i++){
            int ndx = stockPrices[i][0] - stockPrices[i-1][0];
            int ndy = stockPrices[i][1] - stockPrices[i-1][1];
            int m = __gcd(ndx, ndy);
            
            ans += dx != ndx/m || dy != ndy/m;
            
            dx = ndx / m;
            dy = ndy / m;
        }
        
        return ans;
    }
};