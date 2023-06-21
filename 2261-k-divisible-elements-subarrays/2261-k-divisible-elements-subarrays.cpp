class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> st;
        for(int i=0;i<nums.size();i++){
            int count = 0;
            string str = "";
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p==0){
                    count++;
                }
                
                if(count>k){
                    break;
                }
                
                str += nums[j] + '*';
                st.insert(str);
            }
        }
        return st.size();
    }
};