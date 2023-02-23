class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size(), i=0;
        priority_queue<int> pq;
        vector<pair<int,int>> nums;
        
        for(int i=0;i<n;i++){
            nums.push_back({capital[i],profits[i]});
        }
        
        sort(nums.begin(), nums.end());
        
        while(k--){
            while(i<n && nums[i].first<=w){
                pq.push(nums[i].second);
                i++;
            }
            
            if(pq.empty()) break;
            
            w = w + pq.top();
            pq.pop();
        }
        
        return w;
    }
};