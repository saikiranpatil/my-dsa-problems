class Solution {
public:
    char nextGreatestLetter(vector<char>& c, char t) {
        int l = 0;
        int h = c.size() - 1;
        int mid;
        
        while (l <= h) {
            mid = (l + h) / 2;
            if (c[mid] <= t) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return l == c.size() ? c[0] : c[l];
    }
};