class Solution {
public:
    string add_string(string num1, string num2){
        if(num1 == "") return num2;
        if(num2 == "") return num1;
        int m = num1.size(), n = num2.size(), carry = 0, curr;
        string ans = "";
        for(int i=0;i<max(m, n) || carry;i++){
            curr = 0;
            if(i<m) curr += num1[m-i-1] - '0';
            if(i<n) curr += num2[n-i-1] - '0';
            curr += carry;
            carry = curr/10;
            curr %= 10;
            ans = to_string(curr) + ans;
        }
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int m=num1.size(), n=num2.size();
        string ans = "";
        for(int i=m-1;i>=0;i--){
            string curr = "";
            int carry = 0, num;
            for(int j=n-1;j>=0;j--){
                num = (num1[i] - '0') * (num2[j] - '0');
                num += carry;
                carry = num/10;
                num%=10;
                curr = to_string(num) + curr;
            }
            if(carry != 0) curr = to_string(carry) + curr;
            curr += string(m-i-1, '0');
            ans = add_string(ans, curr);
        }
        return ans;
    }
};