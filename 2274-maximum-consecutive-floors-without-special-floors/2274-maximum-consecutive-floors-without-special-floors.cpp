class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& s) {
        s.insert(end(s), {bottom - 1, top + 1});
        sort(begin(s), end(s));
        adjacent_difference(begin(s), end(s), begin(s));
        return *max_element(begin(s) + 1, end(s)) - 1;
    }
};