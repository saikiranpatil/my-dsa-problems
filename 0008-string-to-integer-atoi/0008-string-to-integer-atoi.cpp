class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int x = 0;
        int sign = 1;

        while (s[i] == ' ') {
            ++i;
        }

        if (s[i] != '+' && s[i] != '-' && !isdigit(s[i])) {
            return 0;
        }

        if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }

        while (i != s.size() && isdigit(s[i])) {
            int y = sign * (s[i++] - '0');
            if (sign == 1 && x > (INT_MAX - y) / 10.0) {
                return INT_MAX;
            } else if (sign == -1 && x < (INT_MIN - y) / 10.0) {
                return INT_MIN;
            } 

            x = x*10 + y;
        }

        return x;
    }
};