class Solution {
public:
    string addBinary(string a, string b) {
        int ptr1=a.size()-1, ptr2=b.size()-1;
        int carry=0;
        string ans="";

        while(ptr1>=0 || ptr2>=0 || carry){
            carry += ptr1 >= 0 ? a[ptr1--] - '0' : 0;
            carry += ptr2 >= 0 ? b[ptr2--] - '0' : 0;
            ans = char( carry%2 + '0') + ans;
            carry/=2;
        }

        return ans;
    }
};