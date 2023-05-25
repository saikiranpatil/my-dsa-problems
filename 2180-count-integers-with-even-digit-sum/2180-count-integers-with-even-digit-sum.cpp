class Solution {
public:
    int countEven(int num) {
        int ans=0;
        
        for(int i=1;i<=num;i++){
            int curr=i, curr_sum=0;
            
            while(curr){
                curr_sum+=curr%10;
                curr/=10;
            }
            
            if(curr_sum%2==0) ans++;
        }
        
        return ans;
    }
};