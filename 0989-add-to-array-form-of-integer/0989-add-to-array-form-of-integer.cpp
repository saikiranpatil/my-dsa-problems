class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans=num;
        int idx = num.size() - 1;
        int rem = 0;
        
        while(k || rem){
            int curr = rem;
            if(idx>=0) curr += num[idx];
            if(k>=0) curr += k%10;
            
            k/=10;
            rem = curr / 10;
            curr %=10;
            
            if(idx>=0){
                ans[idx--]=curr;
            }else{
                ans.insert(ans.begin(), curr);
            }
        }
        
        return ans;
    }
};