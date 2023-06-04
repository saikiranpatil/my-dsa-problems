//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            vector<string> nums;
            int idx=0;
            int n=s.size();
            
            while(idx<n){
                if(isdigit(s[idx])){
                    string num="";
                    
                    while(idx<n && isdigit(s[idx])){
                        num+=s[idx++];
                    }
                    
                    nums.push_back(num);
                }else{
                    idx++;
                }
            }
            
            string ans=nums[nums.size()-1];
            idx=nums.size()-2;
            
            for(int i=s.size()-1;i>=0;i--){
                if(isdigit(s[i])) continue;
                ans+=s[i];
                ans+=nums[idx--];
            }
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends