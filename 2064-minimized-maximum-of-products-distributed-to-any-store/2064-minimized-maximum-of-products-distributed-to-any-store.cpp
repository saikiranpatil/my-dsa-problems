class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 1e5;
        int mid;
        int curr;
        
        while(low <= high){
            mid = (low + high) / 2;
            curr = 0;
            
            for(auto q: quantities){
                curr += ceil(q / (mid * 1.0));
            }
            
            if(curr <= n){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return high + 1;
    }
};