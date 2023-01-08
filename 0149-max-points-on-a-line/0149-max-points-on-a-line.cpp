class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if( n == 1) return 1;
        
        int ans = 2;
        for(int i=0; i<n-1; i++){
            map<double, int> count;
            for(int j=0; j<n; j++){
                if(i != j){
                    double slope = atan2((points[j][1]-points[i][1]),(points[j][0]-points[i][0]));
                    count[slope]++;
                    ans = max(ans, count[slope]+1);
                }
            }
        }
        
        return ans;
    }
};