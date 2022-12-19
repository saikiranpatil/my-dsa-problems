class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        
        if(n==0 || numRows==1) return s;
        
        string ans="";
        
        for (int i=0;i<numRows;i++){
            int j=i;
            bool down=true;
            while (j<n){
                ans+=s[j];
                if (i==0 || i==numRows-1){
                    j += 2*numRows-2;
                }else{
                    if(down){
                        j+=2*(numRows-i-1);
                    }else{
                        j+=2*i;
                    }
                    down = !down;
                }
            }
        }
        
        return ans;
    }
};