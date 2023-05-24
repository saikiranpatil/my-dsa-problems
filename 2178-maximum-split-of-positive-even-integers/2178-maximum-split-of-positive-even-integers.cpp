class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        
        vector<long long> ans;
        for(long long i=1;finalSum>=2*i;i++){
            ans.push_back(2*i);
            finalSum-=2*i;
        }
        
        if(finalSum>0){
            long long lst=ans[ans.size()-1];
            
            if(lst>=finalSum){
                finalSum+=lst;
                ans.pop_back();
            }
            
            ans.push_back(finalSum);
        }
        
        return ans;
    }
};