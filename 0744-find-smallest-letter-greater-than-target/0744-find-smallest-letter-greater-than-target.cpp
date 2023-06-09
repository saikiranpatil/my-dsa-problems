class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        char a=l[0];
        for(int i=l.size()-1;i>=0 && l[i]>t;i--) a=l[i];
        return a;
    }
};