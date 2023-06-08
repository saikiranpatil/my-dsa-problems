class Solution {
public:
    bool isValid(vector<int> position, int k, int m){
        int count = 1;
        int prev=0;
        
        for(int i=1;i<position.size();i++){
            if(position[i] - position[prev] >= k){
                count++;
                prev=i;
                
                if(count == m) return true;
            }
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(), position.end());
        
        int low = 0, high = position[n-1] - position[0];
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(isValid(position, mid, m)) low = mid + 1;
            else high = mid - 1;
        }
        
        return low - 1;
    }
};