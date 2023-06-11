class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n);
        
        str+=to_string(2*n);
        str+=to_string(3*n);
        
        vector<int> count(10, 0);
        
        for(auto c: str){
            count[c - '0']++;
        }
        
        for(int i = 1;i < 10;i++){
            if(count[i] != 1) return false;
        }
        
        return count[0] == 0;
    }
};