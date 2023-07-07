class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        int n = tiles.size(), ans = 0, l = 0, r = 0, curr = 0;
        while(ans<carpetLen && r<n){
            if(tiles[l][0] + carpetLen > tiles[r][1]){
                curr += tiles[r][1] - tiles[r][0] + 1;
                ans = max(ans, curr);
                r++;
            }else{
                int partial = max(0, tiles[l][0] + carpetLen - tiles[r][0]);
                ans = max(ans, curr + partial);
                curr -= tiles[l][1] - tiles[l][0] + 1;
                l++;
            }
        }
        return ans;
    }
};