class Solution {
public:
    bool dfs(int x, int y, int row, int col, vector<vector<bool>>& visited) {
        if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) {
            return false;
        }

        if (x == row - 1) {
            return true;
        }

        visited[x][y] = true;

        return dfs(x + 1, y, row, col, visited) || dfs(x - 1, y, row, col, visited) ||
               dfs(x, y + 1, row, col, visited) || dfs(x, y - 1, row, col, visited);
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto isValid = [&](int mid) {
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            for (int i = 0; i <= mid; i++) {
                visited[cells[i][0] - 1][cells[i][1] - 1] = true;
            }

            for (int j = 0; j < col; j++) {
                if (dfs(0, j, row, col, visited)) {
                    return true;
                }
            }

            return false;
        };

        int low = 0, high = cells.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};