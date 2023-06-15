class Solution {
public:
    int largestInteger(int num) {
        int count[10] = {0};
        int idxs[2] = {0,1};
        int ans =0;
        
        for(int n=num;n;n/=10){
            count[n%10]++;
        }
        
        for(long n=num, fact=1;n;fact*=10,n/=10){
            int curr = n % 10 % 2;
            
            while(count[idxs[curr]] == 0){
                idxs[curr]+=2;
            }
            
            ans += fact * idxs[curr];
            count[idxs[curr]]--;
        }
        
        return ans;
    }
};