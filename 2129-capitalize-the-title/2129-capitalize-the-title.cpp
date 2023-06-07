class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int prev = 0;
        
        for (int i = 0; i <= title.size(); ++i) {
            if (i == title.size() || title[i] == ' ') {
                if (i - prev > 2) title[prev] = toupper(title[prev]);
                prev = i + 1;
            }else{
                title[i] = tolower(title[i]);
            }
        }
        return title;
    }
};