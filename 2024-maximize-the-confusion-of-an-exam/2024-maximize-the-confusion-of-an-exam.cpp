class Solution {
public:
    int maxConsecutiveAnswers(string anskey, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int i=0,j=0,n = anskey.length(),ctt=0,ctf=0,ans=0;
        while(j<n){
            if(anskey[j]=='T') ctt++;
            else ctf++;
            while(min(ctf,ctt)>k){
                if(anskey[i]=='T') ctt--;
                else ctf--;
                i++;
            }
            ans =max(ans , j-i+1);
            j++;
        }
        return ans ;
    }
};