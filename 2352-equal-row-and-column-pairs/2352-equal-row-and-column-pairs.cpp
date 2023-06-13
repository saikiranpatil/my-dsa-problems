class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;
        int curr;

        unordered_map<string, int> rows;
        unordered_map<string, int> cols;

        for (int i = 0; i < n; i++)
        {
            string row = "";
            string col = "";

            for (int j = 0; j < n; j++)
            {
                row += "-" + to_string(grid[i][j]);
                col += "-" + to_string(grid[j][i]);
            }

            rows[row]++;
            cols[col]++;
        }

        for (auto row : rows)
        {
            ans += row.second * cols[row.first];
        }

        return ans;
    }
};