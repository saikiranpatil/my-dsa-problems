class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i-1];
            right[n-i-1]=right[n-i]+nums[n-i];
        }
        for(int i=0;i<n-1;i++){
            if(left[i]+nums[i]>=right[i]){
                ans++;
            }
        }
        return ans;
    }
};