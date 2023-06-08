class Solution {
public:
    double timeNeeded(vector<int>& dis, int speed) {
        double time = 0.0;
        for (int i = 0 ; i < dis.size(); i++) {
            double t = (double) dis[i] / (double) speed;
            time += (i == dis.size() - 1 ? t : ceil(t));
        }
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dis, double h) {
        int low=1, high=1e7, ans=-1;
        
        while(low<=high){
            int mid = low + (high - low) / 2;
            
            if(timeNeeded(dis, mid) <= h){
                high=mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        
        return ans;
    }
};