//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
                int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x + 1 < n && image[x + 1][y] == oldColor) {
                image[x + 1][y] = newColor;
                q.push({x + 1, y});
            }
            if (x - 1 >= 0 && image[x - 1][y] == oldColor) {
                image[x - 1][y] = newColor;
                q.push({x - 1, y});
            }
            if (y + 1 < m && image[x][y + 1] == oldColor) {
                image[x][y + 1] = newColor;
                q.push({x, y + 1});
            }
            if (y - 1 >= 0 && image[x][y - 1] == oldColor) {
                image[x][y - 1] = newColor;
                q.push({x, y - 1});
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends