class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size(), ans=0;
        long long num=lower, min_num=lower, max_num=lower;
        
        for(int i=0;i<n;i++){
            num+=differences[i];
            
            min_num=min(min_num, num);
            max_num=max(max_num, num);
        }
        
        return upper - lower - max_num + min_num >=0 ? upper - lower - max_num + min_num + 1 : 0;
    }
};