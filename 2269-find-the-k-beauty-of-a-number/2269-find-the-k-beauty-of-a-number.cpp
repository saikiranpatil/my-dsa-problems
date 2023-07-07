class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        if(str.size()<k) return 0;
        
        int ans = 0, n = str.size();
        for(int i=0;i+k<=n;i++){
            int curr = stoi(str.substr(i, k));
            if(curr && num%curr==0) ans++;
        }
        return ans;
    }
};