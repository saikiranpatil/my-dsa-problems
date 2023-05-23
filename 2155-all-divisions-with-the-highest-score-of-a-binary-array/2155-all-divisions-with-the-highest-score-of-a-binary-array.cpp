class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        unordered_map<int, vector<int>> score_mp;
        int n=nums.size(), score=0;
        vector<int> ans;
        
        for(int i=0;i<n;i++) score+=nums[i];
        
        int max_score=score;
        score_mp[score].push_back(0);
        
        for(int i=0;i<n;i++){
            if(nums[i]==0) score++;
            else score--;
            
            max_score=max(score, max_score);
            score_mp[score].push_back(i+1);
        }
        
        return score_mp[max_score];
    }
};