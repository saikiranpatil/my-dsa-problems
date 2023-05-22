//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        // code here
        vector<int> graph(N, 0);
        int ans=0;
        
        for(int i=1;i<N;i++){
            graph[p[i]]++;
            graph[i]++;
        }
        
        for(int i=0;i<N;i++) if(graph[i]==1) ans++;
        
        return N - ans - 1 < 0 ? 0 : N - ans - 1;
    }
};


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends