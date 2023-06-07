class Solution {
public:
    string capitalizeTitle(string title) {
        int prev = -2;
        int n = title.size();
        
        for(int i=0;i<n;i++){
            title[i] = toupper(title[i]);
            
            while(i+1 < n && title[i+1] != ' '){
                i++;
                title[i]=tolower(title[i]);
            }
            
            if(i-prev < 4) title[prev+2] = tolower(title[prev+2]);
            prev = i++;
        }
        
        return title;
    }
};