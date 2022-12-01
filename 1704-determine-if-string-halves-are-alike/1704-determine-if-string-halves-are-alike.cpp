class Solution {
public:
    bool halvesAreAlike(string s) {
        int ans=0;
        vector<char> alike = {'a','e','i','o','u','A','E','I','O','U'};
        
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<alike.size();j++){
                if(alike[j]==s[i]){
                    if(i<=(s.size()-1)/2){
                        ans++;
                    }else{
                        ans--;
                    }
                    break;
                }
            }
        }
        
        
        return !ans;
    }
};