class Solution {
public:
    char nextGreatestLetter(vector<char>& c, char t) {
        int l=0, h=c.size()-1, m;
        
        while(l<=h){
            m=(l+h)/2;
            if(c[m]>t) h=m-1;
            else l=m+1;
        }
        
        return l==c.size() ? c[0] : c[l];
    }
};