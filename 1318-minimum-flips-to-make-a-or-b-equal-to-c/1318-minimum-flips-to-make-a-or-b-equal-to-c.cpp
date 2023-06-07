class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        
        while(a || b || c){
            bool a_lsb = a%2, b_lsb = b%2, c_lsb = c%2;
            a/=2, b/=2, c/=2;
            
            if((a_lsb || b_lsb) == c_lsb) continue;
            if(a_lsb == true && b_lsb == true) ans++;
            ans++;
        }
        
        return ans;
    }
};