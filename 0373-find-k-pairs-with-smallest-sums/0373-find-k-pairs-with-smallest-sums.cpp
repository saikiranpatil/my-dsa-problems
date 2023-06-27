class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&nums1, &nums2] (const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        vector<vector<int>> ans;
        ans.reserve(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push({0,0});

        while(k-- > 0 && !pq.empty()) {
            const auto [i1, i2] = pq.top();
            pq.pop();

            ans.push_back({nums1[i1], nums2[i2]});

            if(i1 == 0 && i2 + 1 < nums2.size()) {
                pq.push({i1, i2+1});
            }
            if(i1 + 1 < nums1.size()) {
                pq.push({i1+1, i2});
            }
        }

        return ans;
    }
};