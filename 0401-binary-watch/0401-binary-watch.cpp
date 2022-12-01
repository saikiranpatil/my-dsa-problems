class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(countBit(i) + countBit(j) == turnedOn){
                    ans.push_back(to_string(i) + ":" + (j<10 ? "0":"") + to_string(j));
                }
            }
        }
        
        return ans;
    }
    
    int countBit(int n){
        int ans=0;
        
        while(n>0){
            ans += n & 1;
            n >>= 1;
        }
        
        return ans;
    }
};