class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());
        
        while(!pq.empty() && pq.top()<=coins){
            ans++;
            coins-=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};