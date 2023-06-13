class Solution {
public:
    int stti(string str){
        return stoi(str.substr(0,2))*60 + stoi(str.substr(3,2));
    }
    
    int convertTime(string current, string correct) {
        int nums[4] = {60,15,5,1};
        int left = stti(correct) - stti(current);
        int ans = 0;
        
        for(auto num: nums){
            ans += left / num;
            left %= num;
        }
        
        return ans;
    }
};