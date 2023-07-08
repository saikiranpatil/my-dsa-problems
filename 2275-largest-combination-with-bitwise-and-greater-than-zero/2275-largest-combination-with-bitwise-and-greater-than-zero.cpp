static const auto init = []
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return false;
}();
class Solution {
public:
   int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int max_ele = *max_element(candidates.begin(),candidates.end());
        for (int b = 1; b <= max_ele; b<<=1)
        {
            int cnt = 0;
            for(auto n:candidates){
                cnt+=(n&b)>0;
            }
            ans=max(cnt,ans);
        }
        return ans;
    }
};