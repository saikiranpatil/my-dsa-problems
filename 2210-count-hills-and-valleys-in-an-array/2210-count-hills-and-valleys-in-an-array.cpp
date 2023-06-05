class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int ans= 0;
        vector<int> v;
        
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
            while(i!=n-1 && nums[i]==nums[i+1]) i++;
        }
        
        for(int i=1;i<v.size()-1;i++){
            if((v[i] > v[i+1] && v[i] > v[i-1]) || (v[i] < v[i+1] && v[i] < v[i-1])){
                ans++;
            }
        }
        
        return ans;
    }
};