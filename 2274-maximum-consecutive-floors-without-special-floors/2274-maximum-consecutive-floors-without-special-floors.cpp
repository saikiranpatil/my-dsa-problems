class Solution {
public:
    int maxConsecutive(int bottom, int top, std::vector<int>& special) {
        sort(special.begin(), special.end());
        int prev=bottom-1;
        int ans=0;

        for (int i=0;i<special.size();i++){
            int curr=special[i]-prev-1;
            ans=max(ans, curr);
            prev=special[i];
        }

        int last=top-prev;
        ans=max(ans, last);

        return ans;
    }
};