//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        if (n == 0) {
            return 0;
        }
        
        int k = colors[0].size();
        
        vector<vector<int>> dp(n, vector<int>(k, 0));
        
        for (int i = 0; i < k; i++) {
            dp[0][i] = colors[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = INT_MAX;
                for (int prev = 0; prev < k; prev++) {
                    if (prev != j) {
                        dp[i][j] = min(dp[i][j], colors[i][j] + dp[i - 1][prev]);
                    }
                }
            }
        }
        
        int minCost = INT_MAX;
        for (int i = 0; i < k; i++) {
            minCost = min(minCost, dp[n - 1][i]);
        }
        
        return minCost;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends