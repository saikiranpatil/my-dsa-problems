class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n=num2.size();
        string ans(m+n, '0');
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int curr = (ans[i+j+1]-'0') + (num1[i]-'0') * (num2[j]-'0');
                ans[i+j+1] = curr%10 + '0';
                ans[i+j] += curr/10;
            }
        }
        if(ans[0] == '0') return ans.substr(1);
        return ans;
    }
};