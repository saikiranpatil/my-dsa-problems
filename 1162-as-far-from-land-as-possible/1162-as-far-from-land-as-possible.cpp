class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited = grid;
        queue<pair<int, int>> q;
        int n = grid.size();
        int ans = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) 
                    q.push({i, j});
            }
        }
        
        if (q.empty() || q.size() == n * n)  return -1;
        
        while (!q.empty()) {
            int sx = q.size();
            while (sx--) {
                pair<int,int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y=p.second;
        
                for (auto [dx, dy] : dirs) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        
        return ans;
    }
};