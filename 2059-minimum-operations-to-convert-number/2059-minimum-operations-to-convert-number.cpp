class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n=nums.size(), ans=0;
        vector<int> visited(1001,false);
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                
                if(curr==goal) return ans;
                if(curr<0 || curr>1000 || visited[curr]) continue;
                
                visited[curr]=true;
                
                for(int i=0;i<n;i++){
                    q.push(curr + nums[i]);
                    q.push(curr - nums[i]);
                    q.push(curr ^ nums[i]);
                }
            }
            ans++;
        }
        
        return -1;
    }
};