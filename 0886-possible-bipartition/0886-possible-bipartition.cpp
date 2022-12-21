class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> arr(n+1);
        vector<int> color(n+1,0);
        vector<bool> visited(n+1,false);
        
        for(int i=0;i<dislikes.size();i++){
            arr[dislikes[i][0]].push_back(dislikes[i][1]);
            arr[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        queue<int> q;
        
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                color[i]=1;
                q.push(i);
                
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    
                    if(visited[curr]) continue;
                    
                    visited[curr]=true;
                    
                    for(auto v:arr[curr]){
                        if(color[curr]==color[v]) return false;
                        
                        if(color[curr]==1) color[v]=2;
                        else color[v]=1;
                        
                        q.push(v);
                    }
                }
            }
        }
        
        return true;
    }
};