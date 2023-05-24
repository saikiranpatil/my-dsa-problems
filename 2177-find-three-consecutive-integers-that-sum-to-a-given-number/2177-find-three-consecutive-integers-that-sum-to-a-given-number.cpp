class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0) return {};
        long long ans=num/3;
        
        return {ans-1, ans, ans+1};
    }
};