class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {\
        int n=time.size();
        long long low = 0;
        long long high = LLONG_MAX / n;
        
        while (low < high) {
            long long mid = low + (high - low) / 2, curr = 0;
            
            for (auto t: time){
                curr += mid / t;
            }
            
            if (curr < totalTrips){
                low = mid +1;
            }else{
                high = mid;
            }
        }
        
        return low;
    }
};