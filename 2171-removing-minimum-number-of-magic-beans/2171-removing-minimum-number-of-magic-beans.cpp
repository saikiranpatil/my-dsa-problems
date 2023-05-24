class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n=beans.size(), sum=0, ans=0;
        sort(beans.begin(), beans.end());
        
        for(auto num: beans) sum+=num;
        for(int i=0;i<n;i++) ans=max(ans, beans[i] * (n-i));
        
        return sum - ans;
    }
};