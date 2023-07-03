class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        int n = s.size();
        int count1[26] = {0};
        int count2[26] = {0};
        int count = 0, flag = false;
        
        for(int i=0;i<n;i++){
            count1[s[i]-'a']++;
            count2[goal[i]-'a']++;
            
            if(s[i]!=goal[i]){
                count++;
            }
        }
        
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return false;
            }
            
            if(count1[i]>1 && count2[i]){
                flag = true;
            }
        }
        
        return count==2 || (s==goal && flag);
    }
};