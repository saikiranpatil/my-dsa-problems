class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int sum=0;
        vector<int> prefix_sum;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefix_sum.push_back(sum);
        }
        for(int i=0;i<queries.size();i++){
            int num=0;
            for(int j=0;j<prefix_sum.size();j++){
                if(prefix_sum[j]>queries[i]){
                    break;
                }else{
                    num++;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};