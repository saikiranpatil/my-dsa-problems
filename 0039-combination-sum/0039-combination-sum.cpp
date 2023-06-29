class Solution {
public:
    void check(int sum,int i,int n,vector<int>& c,int k,vector<vector<int>>&ans,vector<int>&v)
    {
        if(sum>k)
        {
            return ;
        }
        if(i==n)
        {
            if(sum==k)
            {
                ans.push_back(v);
            }
            return ;
            
        }
      if(c[i]<=k)
      {
          v.push_back(c[i]);
          check(sum+c[i],i,n,c,k,ans,v);
          v.pop_back();
      }
       check(sum,i+1,n,c,k,ans,v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>s;
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>v;
        check(0,0,n,candidates,target,ans,v);
        return ans;
        
    }
};