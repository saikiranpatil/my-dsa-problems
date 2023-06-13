class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        int n = s.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for(int i=1;i<n;i++){
            if(s[i-1] == '1'){
                left[i] = left[i-1] + 1;
            }else{
                left[i] = left[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(s[i+1] == '1'){
                right[i] = right[i+1] + 1;
            }else{
                right[i] = right[i+1];
            }
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans += left[i]*right[i];
            }else{
                ans += (i - left[i]) * (n - i - 1 - right[i]);
            }
        }
        
        return ans;
    }
};