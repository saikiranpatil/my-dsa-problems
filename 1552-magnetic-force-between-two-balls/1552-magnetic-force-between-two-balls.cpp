class Solution {
public:
    int isValid(vector<int>& position, int k){
        int i=1, prev=position[0], count=1;
        
        for(auto num: position){
            if(num < prev + k) continue;
            prev = num;
            count++;
        }
        
        return count;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low=1, high = position.back() - position[0];
        
        while(low <= high){
            int mid = (high + low) / 2;
            
            if(isValid(position, mid)>=m){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return low - 1;
    }
};