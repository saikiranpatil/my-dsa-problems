class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto row : grid){
            int start = 0, end = row.size()-1;
            if(row[end] >= 0)  continue;
            
            if(row[start] < 0) 
            { 
                cnt += row.size(); 
                continue; 
            }
            
            while(start <= end){
                int mid = start + (end - start)/2;
                if(row[mid] < 0) 
                end = mid - 1;
                else 
                start = mid + 1;
            }
            
            cnt += row.size() - start;
        }
        return cnt;
    }
};