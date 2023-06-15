//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    string longestPalin (string s) {
        // code here
        string ans = string(1,s[0]);
        int n = s.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i+1 > ans.size() && isPalin(s, i, j)){
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        
        return ans;
    }
    
    bool isPalin(string& s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends