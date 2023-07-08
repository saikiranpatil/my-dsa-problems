class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for(int i=0;i+1<n;i++){
            int j=i+1;
            while(j<n && nums[j] - nums[j-1] == pow(-1, j-i+1)){
                j++;
            }
            ans = max(ans, j-i);
        }
        return ans == 1 ? -1 : ans;
    }
};