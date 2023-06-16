class Solution {
public:
    string helper(string str, int k){
        string ans = "";
        
        for(int i=0, curr=0;i<str.size();i++){
            curr += str[i] - '0';
            if((i+1)%k==0 || i==str.size()-1){
                ans += to_string(curr);
                curr = 0;
            }
        }
        
        return ans;
    }
    
    string digitSum(string s, int k) {
        string ans = s;
        
        while(ans.size()>k){
            ans = helper(ans, k);
        }
        
        return ans;
    }
};