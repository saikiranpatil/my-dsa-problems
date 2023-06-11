class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n);
        str+=to_string(2*n);
        str+=to_string(3*n);
        
        sort(str.begin(), str.end());
        
        return str == "123456789";
    }
};