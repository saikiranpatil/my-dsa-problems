class Solution {
public:
     struct VectorHasher {
        template <class T>
        std::size_t operator()(const std::vector<T>& vec) const {
            std::size_t seed = vec.size();
            for (const auto& i : vec) {
                seed ^= std::hash<T>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    unordered_set<vector<int>, VectorHasher> st;
    vector<int> tmp;

    void helper(vector<int>& candidates, vector<int> curr, int target, int idx) {
        if (target == 0) {
            st.insert(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                tmp = curr;
                tmp.push_back(candidates[i]);
                helper(candidates, tmp, target - candidates[i], i+1);
            }
            while(i+1<candidates.size() && candidates[i+1]==candidates[i]) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, {}, target, 0);
        vector<vector<int>> ans;
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};