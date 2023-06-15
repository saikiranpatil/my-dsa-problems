class Solution {
public:
    int mx = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        long long ans=1;
        int curr;
        
        while(k--){
            curr = pq.top();
            pq.pop();
            pq.push(curr+1);
        }
        
        while(!pq.empty()){
            ans = (ans* pq.top()) % mx;
            pq.pop();
        }
        
        return ans;
    }
};