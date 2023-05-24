class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int, int>> nums;
        long long ans=0, curr_sum=0;
        
        for(int i=0;i<n;i++) nums.push_back({nums2[i], nums1[i]});
        
        sort(nums.rbegin(), nums.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<k-1;i++){
            pq.push(nums[i].second);
            curr_sum+=nums[i].second;
        }
        
        for(int i=k-1;i<n;i++){
            curr_sum+=nums[i].second;
            ans=max(ans, nums[i].first * curr_sum);
            
            pq.push(nums[i].second);
            curr_sum-=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};