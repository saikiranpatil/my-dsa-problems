class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        
        for(int i=0;i<=n/2;i++){
            if(words[(i + startIndex) % n]==target || words[(startIndex - i + n) % n]==target) return i;
        }
        
        return -1;
    }
};