class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        ans.push_back({points[0][0],points[0][1]});
        
        for(int i=1;i<points.size();i++){
            int lst=ans.size()-1;
            if(ans[lst][1]>=points[i][0]){
                ans[lst][0]=points[i][0];
                ans[lst][1]=min(ans[lst][1], points[i][1]);
            }else{
                ans.push_back({points[i][0], points[i][1]});
            }
        }
        
        return ans.size();
    }
};