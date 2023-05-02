class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = true;
        
        for(auto it: nums){
            if(it==0) return 0;
            else if(it<0) ans=!ans;
        }
        
        return ans ? 1 : -1;
    }
};