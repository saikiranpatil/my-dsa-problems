class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> st;
        queue<int> q;
        
        q.push(0);
        st.insert(0);
        
        while(!q.empty()){
            int curr = q.front();
            
            for(int i=0;i<rooms[curr].size();i++){
                if(!st.count(rooms[curr][i])){
                    q.push(rooms[curr][i]);
                    st.insert(rooms[curr][i]);
                }
            }
            
            q.pop();
        }
        
        return st.size()==rooms.size();
    }
};