class Solution {
public:
    char nextGreatestLetter(vector<char>& c, char t) {
        for(int l=0, h=c.size()-1, m;;){
            m=(l+h)/2;
            if(c[m]>t) h=m-1;
            else l=m+1;
            
            if(l>h) return l==c.size() ? c[0] : c[l];
        }
        return c[0];
    }
};