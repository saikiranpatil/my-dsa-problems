//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int ans=0, count=0;
        bool hasZero=false;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0) continue;
            else count++;
            
            while(i<n && arr[i]!=0) i++;
            if(i<n && arr[i]==0) hasZero=true;
            ans++;
        }
        
        if(!count) return 0;
        
        return hasZero ? ans : -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends