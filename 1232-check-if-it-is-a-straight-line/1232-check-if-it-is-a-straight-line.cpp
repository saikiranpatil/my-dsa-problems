class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        
        if(n<=2) return true;
        
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        
        double m = ((y2-y1)*1.0)/(x2-x1);
        double c = y1 - m*x1;
        
        if(x1==x2){
            for(int i=2;i<n;i++){                
                if(coordinates[i][0]!=x1) return false;
            }
            
            return true;
        }
        
        for(int i=2;i<n;i++){
            int xn = coordinates[i][0];
            int yn = coordinates[i][1];
            
            double equation = yn - m*xn - c;
            
            if(equation != 0) return false;
        }
        
        return true;
    }
};