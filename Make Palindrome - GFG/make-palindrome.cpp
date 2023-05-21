//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPalindrome(string &str)
    {
        string rev = str;
        reverse(rev.begin(), rev.end());
     
        return str == rev;
    }
    
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_set<string> st;
        
        for(int i=0;i<n;i++){
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            
            if(st.find(rev)!=st.end()){
                st.erase(rev);
            }else{
                st.insert(arr[i]);
            }
        }
        
        if(n%2==0) return st.empty();
        
        string last;
        
        for (const string& element : st) {
            last=element;
        }
        
        return st.size()==1 && isPalindrome(last);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends