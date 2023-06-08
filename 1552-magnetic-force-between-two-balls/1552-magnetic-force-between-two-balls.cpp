class Solution {
public:
    bool isValid(vector<int> position, int k, int m){
        for(int i=1, prev=0, count=1;i<position.size();i++){
            if(position[i] - position[prev] >= k){
                count++;
                prev=i;
                
                if(count == m) return true;
            }
        }
        
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int ans=0;
        sort(position.begin(), position.end());
        
        for(int low = 0, high = position[position.size()-1] - position[0];low <= high;){
            int mid = low + (high - low) / 2;
            
            if(isValid(position, mid, m)){
                low = mid + 1;
                ans=mid;
            }else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};