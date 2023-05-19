class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string> ans;
        
        for(int i=0;i<ceil(n/(k*1.0));i++){
            string str="";
            for(int j=0;j<k;j++){
                str+= k*i + j < n ? s[k*i + j] : fill;
            }
            ans.push_back(str);
        }
        
        return ans;
    }
};