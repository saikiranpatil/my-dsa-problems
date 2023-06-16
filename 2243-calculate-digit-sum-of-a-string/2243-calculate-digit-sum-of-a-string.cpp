class Solution {
public:    
    string digitSum(string s, int k) {
        string ans = s;
        string tmp;
        
        while(ans.size()>k){
            tmp="";
            
            for(int i=0, curr=0;i<ans.size();i++){
                curr += ans[i] - '0';
                if((i+1)%k==0 || i==ans.size()-1){
                    tmp += to_string(curr);
                    curr = 0;
                }
            }
            
            ans = tmp;
        }
        
        return ans;
    }
};