class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=1e9;
        
        while(low<high){
            int mid = low + (high - low) / 2;
            int curr = 0;
            
            for(auto pile: piles) curr +=  ceil((pile*1.0) / mid);
            
            if(curr<=h) high=mid;
            else low=mid+1;
        }
        
        return high;
    }
};