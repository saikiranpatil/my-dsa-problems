class Solution {
public:    
    string digitSum(string s, int k) {
        int n = s.size();
        
        if(n<=k){
            return s;
        }
        
        string ans = "";
            
        for(int i=0, curr=0;i<n;i++){
            curr += s[i] - '0';
            if((i+1)%k==0 || i==n-1){
                ans += to_string(curr);
                curr = 0;
            }
        }

        
        return digitSum(ans, k);
    }
};