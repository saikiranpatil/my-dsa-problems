class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {    
        long long curr;
        for(int low=1, high=INT_MAX, mid;low<=high;){
            curr = 0;
            mid = low + (high - low) / 2;
            
            for(auto candy: candies){
                curr += candy/mid;
            }
            
            if(curr >= k){
                low = mid+1;
            }else{
                high = mid-1;
            }
            
            if(low>high) return low-1;
        }
        
        return 1;
    }
};