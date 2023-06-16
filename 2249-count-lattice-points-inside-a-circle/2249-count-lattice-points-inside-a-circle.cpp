class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        int ans = 0;
        
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                for(int idx=0;idx<n;idx++){
                    int x = circles[idx][0], y = circles[idx][1], r = circles[idx][2];
                    
                    if((i-x)*(i-x) + (j-y)*(j-y) <= r*r){
                        ans++;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};