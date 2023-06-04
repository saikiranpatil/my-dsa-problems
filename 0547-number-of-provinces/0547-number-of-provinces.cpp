class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited (n, false);
        queue<int> q;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            
            q.push(i);
            ans++;
            
            while(!q.empty()){
                int curr=q.front();
                visited[curr]=true;
                q.pop();
                
                for(int j=0;j<n;j++){
                    if(j!=curr && !visited[j] && isConnected[curr][j]) q.push(j);
                }
            }
        }
        
        return ans;
    }
};