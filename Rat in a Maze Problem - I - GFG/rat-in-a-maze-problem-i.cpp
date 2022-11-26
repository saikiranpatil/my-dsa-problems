//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(!m[0][0]) return ans;
        
        string str="";
        vector<vector<int>> vis(n , vector<int> (n, 0)); 
        
        vis[0][0]=1;
        
        helper(m, n, 0, 0, str, ans, vis);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
    
    void helper(vector<vector<int>> &m, int n, int x, int y, string str, vector<string> &ans, vector<vector<int>> &vis){
        if(x==n-1 && y==n-1){
            ans.push_back(str);
            return;
        }
        
        vector<int> dx={0,1,0,-1}, dy={-1,0,1,0};
        string path = "LDRU";
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && m[nx][ny] && !vis[nx][ny]){
                vis[nx][ny]=1;
                helper(m, n, nx, ny, str + path[i], ans, vis);
                vis[nx][ny]=0;
            }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends