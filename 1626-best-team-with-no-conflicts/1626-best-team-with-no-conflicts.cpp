class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>arr;
        int n = ages.size();
        
        for(int i = 0;i < n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());

        vector<int> dp(1000,0);
        int ans = 0;
        
        for(int i = 0;i < n;i++){
            for(int j = i;j >= 0;j--){
                if(arr[i].second <= arr[j].second){
                    dp[i] = max(dp[i],dp[j] + arr[i].second);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};