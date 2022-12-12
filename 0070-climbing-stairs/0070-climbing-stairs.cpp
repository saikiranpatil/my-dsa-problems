class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int first=1,second=2;
        for(int i=3;i<=n;i++){
            int tmp=first;
            first=second;
            second+=tmp;
        }
        return second;
    }
};