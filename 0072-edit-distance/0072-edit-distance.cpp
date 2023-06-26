class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        vector<int> prev(n2+1, 0), curr(n2+1, 0);
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0) curr[j] = i==0 ? j : i;
                else curr[j] = word1[i-1]==word2[j-1] ? prev[j-1] : 1 + min({curr[j-1], prev[j], prev[j-1]});
            }
            prev=curr;
        }
        
        return curr[n2];
    }
};