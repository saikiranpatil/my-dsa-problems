class Solution {
public:
    int mod = 1000000007;
    vector<vector<long long>> ncr;
    
    long long helper(vector<int>& nums){
        int n = nums.size();
        if(n<3) return 1;
        
        vector<int> left, right;
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[0]){
                right.push_back(nums[i]);
            }else{
                left.push_back(nums[i]);
            }
        }
        
        long long ans = ncr[n-1][left.size()] % mod;
        long long left_ans = helper(left) % mod;
        long long right_ans = helper(right) % mod;
        
        return (((ans * left_ans) % mod) * right_ans) % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        ncr.resize(n + 1);
        
        for(int i = 0; i < n + 1; ++i){
            ncr[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
            }
        }
        
        long long ans = helper(nums) - 1;
        return ans;
    }
};