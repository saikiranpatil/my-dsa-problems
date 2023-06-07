class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        
        int sz = (intLength - 1) / 2;
        long long base = pow(10, sz);
        
        for(auto query: queries){
            if(query > 9*base){
                ans.push_back(-1);
                continue;
            }
            
            string num = to_string(query + base - 1);
            string rev = reversestr(num);
            
            if(intLength%2) num.pop_back();
            num = num + rev;
            
            long long curr = stol(num);
            ans.push_back(curr);
        }
        
        return ans;
    }
    
    string reversestr(string str){
        reverse(str.begin(), str.end());
        return str;
    }
};