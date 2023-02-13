class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int i=1;i<10;i++){
            helper(i,ans,n);
        }
        
        return ans;
    }
    
    void helper(int i, vector<int>& ans, int n){
        if(i>n) return;    
        
        ans.push_back(i);
        for(int j=0;j<10;j++){ 
            if(10*i + j > n) return;
            helper(10*i+j, ans, n);
        }
    }
};