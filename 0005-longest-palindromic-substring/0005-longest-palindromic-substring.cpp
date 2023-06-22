class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n<2) return s;

        int start = 0, maxLength = 1;
        for (int i=0;i<n;i++) {
            int left=i-1;
            int right=i+1;
            while (left>= 0&&right<n && s[left]==s[right]){
                if (right-left+1>maxLength){
                    start=left;
                    maxLength=right-left+1;
                }
                left--;
                right++;
            }

            left=i;
            right=i+1;
            while (left>=0 && right<n && s[left]==s[right]){
                if (right-left+1 > maxLength) {
                    start=left;
                    maxLength = right-left+1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};
