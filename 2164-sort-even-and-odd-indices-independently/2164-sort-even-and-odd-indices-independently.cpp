class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        
        if(n<3) return nums;
        
        vector<int> odd, even;
        
        for(int i=0;i<n;i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        for(int i=0;i<n;i++){
            if(i%2==0) ans.push_back(even[i/2]);
            else ans.push_back(odd[i/2]);
        }
        
        return ans;
    }
};