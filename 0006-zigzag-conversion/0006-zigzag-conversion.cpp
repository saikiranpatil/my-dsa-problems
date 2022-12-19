class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        
        if(n==0 || numRows==1) return s;
        
        string ans="";
        
        for(int i=0;i<numRows;i++){
            for(int j=i;j<n;j=j+ 2*numRows - 2){
                ans+=s[j];
                if(i!=0 && i!=numRows-1 && j+2*(numRows-i-1)<n){
                    ans+= s[j+2*(numRows-i-1)];
                }
            }
        }
        
        return ans;
    }
};