class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(), low=0, high=0;
        
        for(auto weight: weights){
            low = max(low, weight);
            high+=weight;
        }
        
        while(low<high){
            int mid = low + (high - low) / 2;
            int curr_days = 1, curr_sum=0;
            
            for(auto weight: weights){
                if(curr_sum + weight > mid){
                    curr_sum=0;
                    curr_days++;
                }
                
                curr_sum += weight;
            }
            
            if(curr_days > days){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        
        return low;
    }
};