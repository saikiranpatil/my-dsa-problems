class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        sort(special.begin(),special.end());
        int mx=0,c=0,l=special.size()-1;
        mx=max(special[0]-bottom,mx);
        mx=max(top-special[l],mx);
        for (int i=1;i<=l;i++){
            mx=max(abs(special[i-1]-special[i])-1,mx);
        }
        return mx;
    }
};