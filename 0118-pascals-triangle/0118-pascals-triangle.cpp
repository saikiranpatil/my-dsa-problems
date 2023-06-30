class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i < numRows; i++){
            int c=1;;
            vector<int> tmp;
            for(int j =0;j<=i;j++){
                tmp.push_back(c);
                c= c*(i-j)/(j+1);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};