class Solution {
public:
    bool digitCount(string num) {
       int n = num.size();
        vector<int> count(n, 0);
        for(int i=0;i<n;i++){
            if(num[i] - '0' >= n) return false;
            count[num[i] - '0']++;
        }
        for(int i=0;i<n;i++){
            if(count[i] != num[i]-'0') return false;
        }
        return true;
    }
};