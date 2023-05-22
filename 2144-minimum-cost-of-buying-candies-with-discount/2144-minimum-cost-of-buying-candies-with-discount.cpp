class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans=0, n=cost.size();
        
        for(int i=0;i<n;i++) if((n-i)%3!=0) ans+=cost[i];
        
        return ans;
    }
};