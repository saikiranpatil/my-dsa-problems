class Solution {
public:    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int idx1 = 0, idx2 = n-1;
        long long ans = 0;
        while(k--){
            while(pq1.size() < candidates && idx1 <= idx2){
                pq1.push(costs[idx1++]);
            }
            while(pq2.size() < candidates && idx1 <= idx2){
                pq2.push(costs[idx2--]);
            }

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if(t1 <= t2){
                ans += t1;
                pq1.pop();
            }
            else{
                ans += t2;
                pq2.pop();
            }
        }
        return ans;
    }
};