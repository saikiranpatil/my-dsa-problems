class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size();
        int ans = 0;
        
        for(int x=0;x<=200;x++){
            for(int y=0;y<=200;y++){
                for(int i=0;i<n;i++){
                    int a=circles[i][0],b=circles[i][1],r=circles[i][2];
                    if((a-x)*(a-x) + (b-y)*(b-y) <= r*r){
                        ans++;
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};