class Solution {
public:
    int reverse(int x) {
        int u = 2147483647 / 10;
        int l = -2147483648 / 10;
        int ans=0;
        
        while(x){
            if(ans <= u && ans >= l){
                ans=ans*10+x%10;
                x/=10;
            }else{
                return 0;
            }
        }
        
        return ans;
    }
};