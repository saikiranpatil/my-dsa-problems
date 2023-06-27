class Solution {
public:    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto customComparator = [&](const vector<int>& a, const vector<int>& b){
            return a[0] + a[1] > b[0] + b[1];    
        };
        
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, decltype(customComparator)> pq(customComparator);
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i], nums2[0], 0});
        }
        while(k-- && !pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back({curr[0], curr[1]});
            
            if(curr[2]!=nums2.size()-1){
                pq.push({curr[0], nums2[curr[2]+1], curr[2]+1});
            }
        }
        return ans;
    }
};