class Solution {
public:
    int fib(int n) {
        vector<int> ans = {0,1};
        
        for(int i=2;i<=n;i++) ans.push_back(ans[i-1] + ans[i-2]);
        
        return(ans[n]);
    }
};