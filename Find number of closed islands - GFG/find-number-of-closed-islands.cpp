//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int ans=0;
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==0 || j==0 || i==N-1 || j==M-1){
                    if(matrix[i][j] && !visited[i][j]){
                        helper(matrix, N, M, i, j, visited);
                    }
                }
            }
        }
        
        // printbool(visited);
        
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j] && !visited[i][j]){
                    helper(matrix, N, M, i, j, visited);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void helper(vector<vector<int>>& matrix, int N, int M, int i, int j, vector<vector<bool>>& visited){
        if(i<0 || i==N || j<0 || j==M || visited[i][j] || !matrix[i][j]) return;
        
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        
        visited[i][j]=true;
        
        
        helper(matrix, N, M, i-1, j, visited);
        helper(matrix, N, M, i+1, j, visited);
        helper(matrix, N, M, i, j-1, visited);
        helper(matrix, N, M, i, j+1, visited);
    }
    
    // void printbool( vector<vector<bool>>& visited){
    //     for(int i=0;i<visited.size();i++){
    //         for(int j=0;j<visited[i].size();j++){
    //             cout<<visited[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends