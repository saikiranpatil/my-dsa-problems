class Solution {
public:
    long long smallestNumber(long long num) {
        if(num<10 && num>-10) return num;
        
        long long ans=0;
        vector<int> nums;
        bool positive = num>0;
        
        num=abs(num);
        
        while(num){
            nums.push_back(num%10);
            num/=10;
        }
        
        if(positive){
            sort(nums.begin(), nums.end());
            
            while(nums[0]==0){
                int idx=0;
                while(nums[idx]==0 && idx<nums.size()) idx++;
                swap(nums[idx], nums[0]);
            }
        }
        else{
            sort(nums.rbegin(), nums.rend());
        }
        
        for(int i=0;i<nums.size();i++){
            ans=ans*10 + nums[i];
        }
        
        return positive ? ans : -1 * ans;
    }
};