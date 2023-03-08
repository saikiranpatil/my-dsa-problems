class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=1e9, n=piles.size(), ans=1e9;
        
        while(low<high){
            int mid = low + (high - low) / 2;
            
            int curr = 0;
            
            for(int i=0;i<n;i++){
                curr +=  ceil((piles[i]*1.0) / mid);
            }
            
            if(curr<=h){
                high=mid;
                ans=min(ans, mid);
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};