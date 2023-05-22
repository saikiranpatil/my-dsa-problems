class Solution {
public:    
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        string ans=s;
        
        for(int i=0;i<n/2;i++){
            if(ans[i]==ans[n-i-1]) continue;
            
            if(ans[i]>ans[n-i-1]) ans[i]=ans[n-i-1];
            else ans[n-i-1]=ans[i];
        }
        
        return ans;
    }
};