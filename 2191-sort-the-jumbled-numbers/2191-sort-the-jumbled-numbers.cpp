vector<int> mapper;
    
int mapped_val(int num){
    if(num==0) return mapper[0];
    
    int ans=0;
    int factor=1;
        
    while(num){
        ans+=factor*(mapper[num%10]);
            
        num/=10;
        factor*=10;
    }
        
    return ans;
}

bool comparefn(int a, int b)
{
    return mapped_val(a) < mapped_val(b);
}

class Solution {
public:    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        mapper = mapping;
        
        sort(nums.begin(), nums.end(), comparefn);
        
        return nums;
    }
};