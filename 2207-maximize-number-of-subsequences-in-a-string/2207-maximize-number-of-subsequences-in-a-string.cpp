class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n=text.size();
        
        int count=1;
        long long curr=0;
        
        for(int i=0;i<n;i++){
            if(text[i]==pattern[1]) curr+=count;
            if(text[i]==pattern[0]) count++;
        }
        
        long long ans = curr;
        count=1;
        curr=0;
        
        for(int i=n-1;i>=0;i--){
            if(text[i]==pattern[0]) curr+=count;
            if(text[i]==pattern[1]) count++;
        }
        
        return max(ans, curr);
    }
};