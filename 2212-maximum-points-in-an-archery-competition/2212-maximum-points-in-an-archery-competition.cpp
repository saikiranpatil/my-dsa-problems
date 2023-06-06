class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int score=0;
        int idx=0;
        
        for(int i=1;i<=pow(2, 12);i++){
            // cout<<i<<endl;
            int curr = 0;
            int currArrows = numArrows;
            
            for(int j=0;j<12;j++){
                // cout<<((i>>j)&1)<<" ";
                if((i>>j)&1){
                    if(currArrows < aliceArrows[j] + 1) continue;
                    
                    currArrows -= aliceArrows[j] + 1;
                    curr += j;
                }
            }
    
            // cout<<endl<<endl;
            
            if(curr>score){
                idx=i;
                score=curr;
            }
        }
        
        cout<<idx<<" "<<score<<endl;
        
        vector<int> ans(12, 0);
        
        for(int i=0;i<12;i++){
            if((idx>>i)&1){
                ans[i]=aliceArrows[i] + 1;
                numArrows-=aliceArrows[i] + 1;
            }
        }
        
        ans[0] += numArrows;
        
        return ans;
    }
};