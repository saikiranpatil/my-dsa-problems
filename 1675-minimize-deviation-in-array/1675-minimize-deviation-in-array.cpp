class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        priority_queue<int> pq;
        int mn=INT_MAX, ans=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) nums[i]*=2;
            pq.push(nums[i]);
            mn=min(mn, nums[i]);
        }
        
        while(true){
            int curr = pq.top();
            pq.pop();
            
            ans = min(ans, curr-mn);
            
            if(curr%2) break;
            
            mn=min(mn, curr/2);
            pq.push(curr/2);
        }
        
        return ans;
    }
};