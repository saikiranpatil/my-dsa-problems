class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), i=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        
        for(int i=0; i<n; i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        
        long long t = tasks[0][0];
        
        while(!pq.empty() or i<n)
        {
            while(i<n && t>=tasks[i][0]) pq.push({tasks[i][1],tasks[i++][2]});

           
            if(pq.empty()){
                t = tasks[i][0];
            }
            else{
               pair<int,int> p = pq.top();
               pq.pop();
               ans.push_back(p.second);
               t += p.first; 
            }  
        }
        return ans;
    }
};