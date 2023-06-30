class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int> v;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                v.push_back(num[i] - '0');
                v.push_back(num[i + 1] - '0');
                v.push_back(num[i + 2] - '0');
                i += 2;
            }
        }
        sort(v.begin(), v.end());
        if (v.empty()) {
            return "";
        } else {
            string result;
            result.push_back(v[v.size() - 1] + '0');
            result.push_back(v[v.size() - 2] + '0');
            result.push_back(v[v.size() - 3] + '0');
            return result;
        }
    }
};