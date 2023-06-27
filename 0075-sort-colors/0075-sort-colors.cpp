class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first = 0, second = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[i], nums[second]);
                swap(nums[second], nums[first]);
                first++;
                second++;
            }
            else if(nums[i] == 1){
                swap(nums[i], nums[second]);
                second++;
            }
        }
    }
};    