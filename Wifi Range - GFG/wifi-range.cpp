//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int ans=0;
        vector<int> nums(N,0);
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                nums[i]=1;
                for(int j=i-X;j<=i+X;j++){
                    if(j>=0 && j<N && S[j]!='1' && i!=j){
                        nums[j]=2;
                    }
                }
            }
        }
        
        for(int i=0;i<N;i++) if(nums[i]==0) ans++;
        
        return ans==0;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends