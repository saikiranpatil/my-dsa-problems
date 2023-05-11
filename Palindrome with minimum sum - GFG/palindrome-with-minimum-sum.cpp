//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        vector<char> nums;
        int n = s.length(), ans=0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]!=s[n-i-1])
            {
                if(s[i]=='?') s[i] = s[n-i-1];
                else if(s[n-i-1]=='?') s[n-i-1] = s[i];
                else return -1;
            }
            if(s[i]!='?') nums.push_back(s[i]);
        }
        
        if(nums.size()<=1) return 0;

        for(int i=1; i<nums.size(); i++) ans += abs(nums[i]-nums[i-1]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends