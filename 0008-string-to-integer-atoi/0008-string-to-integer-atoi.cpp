class Solution {
public:
    int myAtoi(string s) {
        long long ans=0, mx=pow(2,31);
        int idx=0, n=s.size();
        bool isNeg = false;
        while(idx<n && s[idx]==' ') idx++;
        if(s[idx]=='-' || s[idx]=='+'){
            if(s[idx]=='-'){
                isNeg=true;
            }
            idx++;
        }
        while(idx<n && s[idx]>='0' && s[idx]<='9'){
            if(ans>pow(2,31)){
                break;
            }
            ans*=10;
            ans+=s[idx]-'0';
            idx++;
        }
        if(isNeg){
            ans*=-1;
            return max(-1*mx,ans);
        }
        return min(ans, mx-1);
    }
};