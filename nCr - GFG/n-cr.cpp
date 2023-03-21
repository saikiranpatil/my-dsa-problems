//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        if(n==r) return 1;
        
        vector<vector<int>> dp(n+1,vector<int>(r+1,1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
                if(i==j || i==0 || j==0) dp[i][j]=1;
                else if(j==1) dp[i][j]=i;
                else dp[i][j]=(dp[i-1][j] + dp[i-1][j-1]) % 1000000007;
            }
        }
        
        return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends