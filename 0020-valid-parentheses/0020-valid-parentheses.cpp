class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(stk.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')){
                return 0;
            }
            if(!stk.empty() && (s[i]==')' && stk.top()=='(') || (s[i]=='}' && stk.top()=='{') || (s[i]==']' && stk.top()=='[')){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};