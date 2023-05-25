class Solution {
public:
    int countEven(int num) {
        int ans=0;
        
        for(int i=1;i<=num;i++){
            string s=to_string(i);
            int curr=0;
            
            for(int i=0;i<s.size();i++) curr+=s[i] - '0';
            
            if(curr%2==0) ans++;
        }
        
        return ans;
    }
};