class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int c=0;c<=1;c++)
            {
                if(c==1)
                curr[c]=max((-prices[ind]+front1[0]),front1[1]);
                else
                curr[c]=max((prices[ind]+front2[1]),front1[0]);
            }
            front2=front1;
            front1=curr;
        }
        return front1[1];
        
    }
};