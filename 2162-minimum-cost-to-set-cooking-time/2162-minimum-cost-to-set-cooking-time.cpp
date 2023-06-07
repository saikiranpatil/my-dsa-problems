class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int m = targetSeconds / 60, s = targetSeconds %60;
        
        return min(cost(startAt, moveCost, pushCost, m, s), cost(startAt, moveCost, pushCost, m - 1, s + 60));
    }
    
    int cost(int pos, int moveCost, int pushCost, int m, int s){
        if(min(m, s) < 0 || max(m, s) > 99) return INT_MAX;
        
        int ans=0;
        for(auto digit : to_string(m * 100 + s)){
            ans += pushCost + (pos == digit - '0' ? 0 : moveCost);
            pos = digit - '0';
        }
        
        return ans;
    }
};