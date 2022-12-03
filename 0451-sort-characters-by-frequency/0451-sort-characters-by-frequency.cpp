class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<pair<int,char>> p;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto it:mp){
            p.push_back({it.second,it.first});
        }
        
        sort(p.rbegin(),p.rend());
        
        for(auto it:p){
            while(it.first){
                ans+=it.second;
                it.first--;
            }
        }
        
        return ans;
    }
};