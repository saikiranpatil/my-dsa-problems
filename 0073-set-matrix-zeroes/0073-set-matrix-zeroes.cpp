class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> visit = matrix;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<c; k++){
                        visit[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<r; k++){
                        visit[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                matrix[i][j] = visit[i][j];
            }
        }
    }
};