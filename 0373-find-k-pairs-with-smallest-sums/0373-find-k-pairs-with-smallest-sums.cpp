class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<n1;i++){
            pq.push({nums1[i]+nums2[0], nums1[i], nums2[0], 0});
        }
        
        while(k-- && !pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            ans.push_back({curr[1], curr[2]});
            
            if(curr[3]!=n2-1){
                pq.push({curr[1]+nums2[curr[3]+1], curr[1], nums2[curr[3]+1], curr[3]+1});
            }
        }
        return ans;
    }
};