//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N+1,vector<long long>(sum+1,0));
        
        for(int i=0;i<=N;i++) dp[i][0]=1;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(j>=coins[i-1]) dp[i][j]=dp[i][j-coins[i-1]] + dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends