class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int> pq(piles.begin(),piles.end());
        
        while(k--){
            pq.push(ceil(pq.top()/2.0));
            pq.pop();
        }
        
        for(int i=0;i<piles.size();i++){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};