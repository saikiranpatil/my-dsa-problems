class Solution {
public:
    int reverse(int x) {
        int u =  (pow(2,31) - 1)/10;
        int l = -(pow(2,31)/10);
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