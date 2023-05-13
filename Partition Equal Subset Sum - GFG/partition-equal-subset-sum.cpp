//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int num=0;
        
        for(int i=0;i<N;i++){
            num+=arr[i];
        }
        
        if(num%2 != 0) return false;
        num/=2;
        
        vector<vector<bool>> dp(N+1, vector<bool>(num+1, false));
        
        for(int i=0;i<=N;i++) dp[i][0]=true;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=num;j++){
                if(j>=arr[i-1]) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][num];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends