class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n = queries.size();
        vector<long long> ans(n, -1);
        
        int sz = (intLength - 1) / 2;
        long long base = pow(10, sz);
        
        for(int i = 0;i < n;i++){
            if(queries[i] > 9*base) continue;
            
            long long curr = base + queries[i] - 1, tmp = curr;
            
            if(intLength%2) tmp /= 10;
            
            while(tmp){
                curr = curr * 10 + tmp%10;
                tmp /= 10;
            }
            
            ans[i] = curr;
        }
        
        return ans;
    }
};