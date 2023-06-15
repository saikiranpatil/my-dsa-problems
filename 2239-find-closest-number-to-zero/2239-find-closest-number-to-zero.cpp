class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans=INT_MAX;
        
        for(auto num:nums){
            if(abs(ans) == abs(num)){
                ans = max(ans, num);
            }else if(abs(ans) > abs(num)){
                ans = num;
            }
        }
        
        return ans;
    }
};