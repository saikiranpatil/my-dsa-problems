class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> tmp;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(tmp.find(board[i][j])!=tmp.end()){
                        return false;
                    }else{
                        tmp.insert(board[i][j]);
                    }
                }
            }
        }

        for(int j=0;j<9;j++){
            unordered_set<char> tmp;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    if(tmp.find(board[i][j])!=tmp.end()){
                        return false;
                    }else{
                        tmp.insert(board[i][j]);
                    }
                }
            }
        }

        for(int count=0;count<9;count++){
            unordered_set<char> tmp;
            int dx=count/3, dy=count%3;
            for(int i=3*dx;i<3+3*dx;i++){
                for(int j=3*dy;j<3+3*dy;j++){
                    if(board[i][j]!='.'){
                        if(tmp.find(board[i][j])!=tmp.end()){
                            return false;
                        }else{
                            tmp.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};