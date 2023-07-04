class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};